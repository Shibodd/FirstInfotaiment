#include "main.h"
#include "cmsis_os.h"

#include "pin.h"
#include "spi.h"
#include "mcp2515.h"
#include "spi0.h"
#include "stm_pin.h"


extern osMessageQueueId_t guiToMainMsgQueue;
extern osMessageQueueId_t mainToGuiMsgQueue;
extern SPI_HandleTypeDef hspi2;

displayInfo msgDisplayInfo;
int gear_six_count = 0, gear_mem = 0;

MmrPin mcp2515csPin;
MmrPin* spiSlavePins[] = { &mcp2515csPin };


void userMessage(const char* msg) {

}

void userError(const char* msg) {

}


// STEERING WHEEL BUTTONS

typedef struct SteeringButton {
  int pendingPresses;
  MmrPin mmr_pin;
  void (*handler)(struct SteeringButton*);
  uint32_t last_press_tick;
} SteeringButton;

void voidHandler(SteeringButton * btn) {
  btn->pendingPresses = 0;
  ++msgDisplayInfo.rpm;
  osMessageQueuePut(mainToGuiMsgQueue, &msgDisplayInfo, 0U, 0U);
}

#define STEERING_BUTTONS_COUNT 6
SteeringButton steeringButtons[STEERING_BUTTONS_COUNT];
void register_steering_button(GPIO_TypeDef* port, uint16_t pin, bool hasInvertedLogic, void (*handler)(SteeringButton*)) {
	static int i = 0;
	if (i >= STEERING_BUTTONS_COUNT)
		Error_Handler();

	SteeringButton* btn = &steeringButtons[i++];
	btn->mmr_pin = MMR_Pin(port, pin, hasInvertedLogic);
	btn->handler = handler;
	btn->last_press_tick = 0;
}

void initialize_steering_buttons() {
	register_steering_button(STEERING_GEAR_UP_GPIO_Port, STEERING_GEAR_UP_Pin, true, voidHandler);
	register_steering_button(STEERING_GEAR_DOWN_GPIO_Port, STEERING_GEAR_DOWN_Pin, true, voidHandler);
	register_steering_button(STEERING_BLACK_BUTTON_GPIO_Port, STEERING_BLACK_BUTTON_Pin, true, voidHandler);
	register_steering_button(STEERING_GREEN_BUTTON_GPIO_Port, STEERING_GREEN_BUTTON_Pin, true, voidHandler);
	register_steering_button(STEERING_LEFT_RED_BUTTON_GPIO_Port, STEERING_LEFT_RED_BUTTON_Pin, true, voidHandler);
	register_steering_button(STEERING_RIGHT_RED_BUTTON_GPIO_Port, STEERING_RIGHT_RED_BUTTON_Pin, true, voidHandler);
}

void process_steering_buttons() {
  for (int i = 0; i < STEERING_BUTTONS_COUNT; ++i) {
    SteeringButton* btn = &steeringButtons[i];
    if (btn->pendingPresses > 0)
      btn->handler(btn);
  }
}

MmrPinState dbgPinState;
#define DEBOUNCE_TICKS 200
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  for (int i = 0; i < STEERING_BUTTONS_COUNT; ++i) {
    SteeringButton* btn = &steeringButtons[i];
    if (GPIO_Pin == btn->mmr_pin.pin) {
    	// Debounce the interrupt, because the board implements no debounce at all
    	uint32_t tick = HAL_GetTick();
		if (tick - btn->last_press_tick > DEBOUNCE_TICKS) {

			// Check if the button is actually pressed:
			// Another button on the same pin (but different port) may have triggered the interrupt;
			// Also, the board is very trigger-happy and without this check it would trigger an interrupt multiple times even after the button is released.
			MmrPinState state = MMR_PIN_Read(&btn->mmr_pin);
			if (state == MMR_PIN_HIGH) {
				++btn->pendingPresses;
				btn->last_press_tick = tick;
			}
		}
    }
  }
}


// Main logic

void process_gui_message(guiToMainMsg* msg) {
  // do stuff
  MmrCanMessage txMsg;
	uint8_t txPayload[] = { msg->missionType };

	MMR_CAN_MESSAGE_SetId(&txMsg, 254);
	MMR_CAN_MESSAGE_SetStandardId(&txMsg, true);
	MMR_CAN_MESSAGE_SetPayload(&txMsg, txPayload, sizeof(txPayload));

	if (!MMR_CAN_Send(&mcp2515, &txMsg))
    Error_Handler();
}

void process_can_message(MmrCanMessage* msg) {
  if (!msg->isStandardId)
    return;

  switch (msg->id) {
    /* RES */
    case 0x191:
      msgDisplayInfo.RES = msg->payload[0];  /* 0 = emergency, 1 = GO */
      break;

    /* RPM, SPEED, GEAR, ATH */
    case 0x702:
      msgDisplayInfo.rpm = (msg->payload[1] << 8) | msg->payload[0];

      uint16_t speed = (msg->payload[3] << 8) | msg->payload[2];
      msgDisplayInfo.speed = (unsigned char)(speed / 100);

      uint8_t gear = msg->payload[4]; /* No need to read msg->payload[5] since it will ALWAYS be 0! */
      gear_mem = gear;
      if (gear == 6)
      {
        gear_six_count++;
        if (gear_six_count == 3)
          msgDisplayInfo.gear = gear;
      }
      else
      {
        gear_six_count = 0;
        msgDisplayInfo.gear = gear;
      }

      uint16_t throttle = (msg->payload[7] << 8) | msg->payload[6];
      msgDisplayInfo.throttle_perc = (unsigned char)(throttle / 100);
      break;

    /* TOIL, TWATER */
    case 0x701:
      msgDisplayInfo.T_oil = (msg->payload[0] - 40);/* No need to read RxData[1] since it will ALWAYS be 0! */
      msgDisplayInfo.T_water = (msg->payload[2] - 40); /* No need to read RxData[3] since it will ALWAYS be 0! */
      break;

    /* POIL */
    case 0x703: {
      short p_oil = (msg->payload[1] << 8) | msg->payload[0];
      msgDisplayInfo.P_oil = (float)p_oil / 20;
      break;
    }

    /* battery_V * 1000 */
    case 0x704: {
      short bat = (msg->payload[1] << 8) | msg->payload[0];
      msgDisplayInfo.battery_v = (float)bat / 1000;
      break;
    }

    /* LAUNCH CONTROL ACTIVE */
    case 0x70C:
      msgDisplayInfo.LC = msg->payload[0] & 0x1;
      break;

    /* CLUTCH PULL OK */
    // TODO: check IDS!
    case 0x004000E1:
    case 0x104000E1:
      msgDisplayInfo.CLT = true; /* No need to read RxData[7] since it will ALWAYS be 0! */
      break;

    /* CLUTCH RELEASE OK */
    // TODO: check IDS!
    case 0x004000E3:
    case 0x104000E3:
      msgDisplayInfo.CLT = false; /* No need to read RxData[7] since it will ALWAYS be 0! */
      break;

    default:
      return;
  }

  // If no case matched (only the default case did), this is not reached.
  // Send a message containing the updated data to the display thread.
  osMessageQueuePut(mainToGuiMsgQueue, &msgDisplayInfo, 0U, 0U);
}

void userDefaultTask() {
  // Initialize the MMR libraries
  userMessage("INFO: Initialization...");

  initialize_steering_buttons();

  mcp2515csPin = MMR_Pin(MCP2515_CS_GPIO_Port, MCP2515_CS_Pin, true);
  if (!MMR_SPI0_Init(&hspi2, spiSlavePins, 1))
	  userError("ERROR: MMR SPI0 Init failed.");

  MMR_MCP2515_Init(&spi0, 0);


  userMessage("INFO: Resetting MCP2515...");
  while (!MMR_MCP2515_ResetAsync(10)) {
	  if (MMR_MCP2515_GetLastError() != MMR_MCP2515_ERROR_OK)
		  userError("ERROR: MCP2515 reset failed.");

	  osDelay(200);
  }


  userMessage("INFO: Configuring MCP2515 timings...");
  // MCP2515 setup
  if (!MMR_MCP2515_ConfigureCANTiming(MMR_MCP2515_TIMING_8MHz_1000kBPS))
	  userError("ERROR: MCP2515 Timings configuration failed.");


  userMessage("INFO: Configuring MCP2515 filter...");
  MmrCanFilter fil = MMR_CAN_Filter(0, 0, false);
  if (!MMR_CAN_SetFilter(&mcp2515, &fil))
	  userError("ERROR: MCP2515 Filter configuration failed.");


  userMessage("INFO: Switching MCP2515 mode...");
  while (!MMR_MCP2515_SwitchModeAsync(MMR_MCP2515_MODE_NORMAL, 10)) {
    if (MMR_MCP2515_GetLastError() != MMR_MCP2515_ERROR_OK)
      userError("ERROR: MCP2515 mode switch failed.");

    osDelay(200);
  }


  userMessage("INFO: Running.");

  uint8_t rxBuf[8];
  MmrCanMessage rxMsg;
  MMR_CAN_MESSAGE_SetPayload(&rxMsg, rxBuf, 8);

  while (true) {
    int pendingCanMsgs = MMR_CAN_GetPendingMessages(&mcp2515);
    for (int i = 0; i < pendingCanMsgs; ++i) {
      if (MMR_CAN_Receive(&mcp2515, &rxMsg))
        process_can_message(&rxMsg);
      else if (MMR_MCP2515_GetLastError() != MMR_MCP2515_ERROR_NO_PENDING_MESSAGE)
        userMessage("WARN: Message reception failed.");
    }

    int pendingGuiMsgs = osMessageQueueGetCount(guiToMainMsgQueue);
    for (int i = 0; i < pendingGuiMsgs; ++i)
    {
      guiToMainMsg msg;
      osMessageQueueGet(guiToMainMsgQueue, &msg, NULL, 0);
      process_gui_message(&msg);
    }

    process_steering_buttons();
  }
}


