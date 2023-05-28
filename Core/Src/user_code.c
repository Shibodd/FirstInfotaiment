#include "main.h"
#include "gui_shared_defs.h"
#include "cmsis_os.h"

#include <pin.h>
#include <button.h>
#include <spi.h>
#include <mcp2515.h>
#include <spi0.h>
#include <stm_pin.h>
#include <timing.h>
#include <delay.h>
#include <net.h>
#include <util.h>
#include <buffer.h>


extern osMessageQueueId_t dbgMsgQueue;
extern osMessageQueueId_t guiToMainMsgQueue;
extern osMessageQueueId_t valueUpdatesQueue;
extern SPI_HandleTypeDef hspi2;

struct CarState {
  int gear;
  int rpm;
  MmrLaunchControlState launchControlState;
} carState;



MmrPin mcp2515csPin;
MmrPin* spiSlavePins[] = { &mcp2515csPin };

#include <string.h>
void userMessage(const char* msg) {
  osMessageQueuePut(dbgMsgQueue, &msg, 0U, 0U);
  osThreadYield();
}

void userError(const char* msg) {
	userMessage(msg);
	while (true) {
		osDelay(1000);
	}
}


// STEERING WHEEL BUTTONS

typedef struct SteeringButton {
  MmrPin mmr_pin;
  MmrButton mmr_button;
} SteeringButton;



SteeringButton rightPaddleBtn;
SteeringButton leftPaddleBtn;
SteeringButton greenBtn;
SteeringButton leftRedBtn;
SteeringButton rightRedBtn;
// SteeringButton blackButton;

// Mappings
#define SHIFT_UP_BTN rightPaddleBtn
#define SHIFT_DOWN_BTN leftPaddleBtn
#define SHIFT_NTRL_BTN greenBtn
#define MISSION_MANUAL_BTN leftRedBtn
#define SET_LAUNCHCTRL_BTN rightRedBtn

void init_button(SteeringButton* btn, GPIO_TypeDef* port, uint16_t pin, bool hasInvertedLogic) {
	btn->mmr_pin = MMR_Pin(port, pin, hasInvertedLogic);
	btn->mmr_button = MMR_Button(&btn->mmr_pin);
}

void initialize_steering_buttons() {
	init_button(&leftPaddleBtn,  STEERING_LEFT_PADDLE_BUTTON_GPIO_Port,	 STEERING_LEFT_PADDLE_BUTTON_Pin,	false);
	init_button(&rightPaddleBtn, STEERING_RIGHT_PADDLE_BUTTON_GPIO_Port, STEERING_RIGHT_PADDLE_BUTTON_Pin, 	false);
	init_button(&greenBtn,	     STEERING_GREEN_BUTTON_GPIO_Port,	     STEERING_GREEN_BUTTON_Pin,			false);
	init_button(&leftRedBtn,	 STEERING_LEFT_RED_BUTTON_GPIO_Port,     STEERING_LEFT_RED_BUTTON_Pin,  	false);
	init_button(&rightRedBtn, 	 STEERING_RIGHT_RED_BUTTON_GPIO_Port,    STEERING_RIGHT_RED_BUTTON_Pin, 	false);
	// blackButton = init_button(STEERING_BLACK_BUTTON_GPIO_Port, STEERING_BLACK_BUTTON_Pin, true);
}

typedef enum EcuTask {
	ECU_Task_None,
	ECU_Task_ShiftingUp,
	ECU_Task_ShiftingDown,
	ECU_Task_ShiftingNtrl,
	ECU_Task_SetLaunchCtrl,
	ECU_Task_UnsetLaunchCtrl
} EcuTask;

int ecu_task_requests = 0;
EcuTask runningEcuTask = ECU_Task_None;
bool ecu_task_request(EcuTask task) {
  ++ecu_task_requests;

  if (runningEcuTask == ECU_Task_None) {
    runningEcuTask = task;
    return true;
  }
  return false;
}

void task_run_ecu_tasks() {
	static MmrDelay lcTimeout = { .ms = 500 };

	bool finished = false;
	switch (runningEcuTask) {
		case ECU_Task_None:
			return;

		case ECU_Task_ShiftingUp:
			if ((finished = MMR_NET_GEAR_ShiftUpAsync(&mcp2515, carState.gear)))
			  userMessage("INFO: Shifted up.");
			break;

		case ECU_Task_ShiftingDown:
			if ((finished = MMR_NET_GEAR_ShiftDownAsync(&mcp2515, carState.gear)))
			  userMessage("INFO: Shifted down.");
			break;

		case ECU_Task_ShiftingNtrl:
			if ((finished = MMR_NET_GEAR_ShiftToNeutralAsync(&mcp2515, carState.gear)))
			  userMessage("INFO: Shifted to neutral.");
			break;

		case ECU_Task_SetLaunchCtrl:
		case ECU_Task_UnsetLaunchCtrl:
			if ((finished = MMR_DELAY_WaitOnceAsync(&lcTimeout))) {
				lcTimeout.start = 0;
				userMessage("WARN: Launch control toggle FAILED.");
				break;
			}

			MmrNetLaunchControlCarState cs = {
				.rpm = carState.rpm,
				.gear = carState.gear,
				.launchControl = carState.launchControlState
			};

			if (runningEcuTask == ECU_Task_SetLaunchCtrl) {
				if ((finished = MMR_NET_LaunchControlSetAsync(&mcp2515, cs))) {
					userMessage("INFO: Launch control set.");
				}
			} else {
				if ((finished = MMR_NET_LaunchControlUnsetAsync(&mcp2515, cs))) {
					userMessage("INFO: Launch control unset.");
				}
			}

			break;
	}

	if (finished)
		runningEcuTask = ECU_Task_None;
}



// Helpers for CAN
typedef struct {
  bool (*action)();
  MmrDelay interval;
  int repetitions;

  // State
  int __currentRepetition;
} RepeatAsyncParams;

MmrTaskResult RepeatAsync(RepeatAsyncParams* params) {
  if (params->__currentRepetition >= params->repetitions) {
    params->__currentRepetition = 0;
    return MMR_TASK_COMPLETED;
  }
  
  if (MMR_DELAY_WaitAsync(&params->interval)) {
    if (!params->action) {
      params->__currentRepetition = 0;
      return MMR_TASK_ERROR;
    }
    ++params->__currentRepetition;
  }
  return MMR_TASK_PENDING;
}

bool sendCanMessage(MmrCanMessageId id, uint8_t* buf, uint8_t length) {
  MmrCanMessage txMsg;
  MMR_CAN_MESSAGE_SetId(&txMsg, id);
  MMR_CAN_MESSAGE_SetStandardId(&txMsg, true);
  MMR_CAN_MESSAGE_SetPayload(&txMsg, buf, length);
  return MMR_CAN_Send(&mcp2515, &txMsg);
}


// Mission request
int mission_requests = 0;
bool isSwitchingMission = false;
MmrMission selectedMission;

void mission_request(MmrMission mission) {
  if (!isSwitchingMission) {
	  selectedMission = mission;
	  isSwitchingMission = true;
	  ++mission_requests;
  }
}

bool sendMissionRequest() {
  return sendCanMessage(MMR_CAN_MESSAGE_ID_M_MISSION_SELECTED, &selectedMission, 1);
}

RepeatAsyncParams sendMissionRequestRepeatAsync = {
  .action = sendMissionRequest,
  .interval = (MmrDelay) { .ms = 50 },
  .repetitions = 5
};


// RES operational mode
bool isSendingResOpMode;
void resOpMode_request() {
  isSendingResOpMode = true;
}

bool sendResOpMode() {
  static uint8_t buf[1] = { 0x01 };
  return sendCanMessage(MMR_CAN_MESSAGE_ID_RES_NMT, buf, sizeof(buf));
}

RepeatAsyncParams sendResOpModeRepeatAsync = {
  .action = sendResOpMode,
  .interval = (MmrDelay) { .ms = 50 },
  .repetitions = 5
};


// Main logic
void process_single_gui_message(guiToMainMsg* msg) {
  switch (msg->type) {
    case GUI_TO_MAIN_MSG_MISSIONSELECT:
      mission_request(msg->content.selectedMission);
      break;
    
    case GUI_TO_MAIN_MSG_SETRESOPMODE:
      resOpMode_request();
      break;
  }
}

void task_process_gui_messages_rx() {
  int pendingGuiMsgs = osMessageQueueGetCount(guiToMainMsgQueue);
  for (int i = 0; i < pendingGuiMsgs; ++i)
  {
    guiToMainMsg msg;
    osMessageQueueGet(guiToMainMsgQueue, &msg, NULL, 0);
    process_single_gui_message(&msg);
  }
}


#define SEND_VALUE_UPDATE_FUNCTION_DEF(name, type) \
static inline void name(ValueUpdateId id, type data) { \
  valueUpdateMessage msg; \
  msg.id = id; \
  *((type*)msg.value) = data; \
  osMessageQueuePut(valueUpdatesQueue, &msg, 0U, 0U); \
}

SEND_VALUE_UPDATE_FUNCTION_DEF(sendValueUpdate8, uint8_t)
SEND_VALUE_UPDATE_FUNCTION_DEF(sendValueUpdate16, uint16_t)
SEND_VALUE_UPDATE_FUNCTION_DEF(sendValueUpdateBool, bool)
SEND_VALUE_UPDATE_FUNCTION_DEF(sendValueUpdateFloat, float)

void process_single_can_message(MmrCanMessage* msg) {
  if (!msg->isStandardId)
    return;

  switch (msg->id) {
    case MMR_CAN_MESSAGE_ID_RES:
      sendValueUpdateBool(VALUE_UPDATE_ID_RES, 1 == MMR_BUFFER_ReadByte(msg->payload, 0)); /* 0 = emergency, 1 = GO */
      break;

    case MMR_CAN_MESSAGE_ID_ECU_ENGINE_FN1:
      sendValueUpdate16(VALUE_UPDATE_ID_RPM, carState.rpm = MMR_BUFFER_ReadUint16(msg->payload, 0, MMR_ENCODING_LITTLE_ENDIAN));
      sendValueUpdate16(VALUE_UPDATE_ID_SPEED, MMR_BUFFER_ReadUint16(msg->payload, 2, MMR_ENCODING_LITTLE_ENDIAN) / 100);
      sendValueUpdate8(VALUE_UPDATE_ID_GEAR, carState.gear = MMR_BUFFER_ReadByte(msg->payload, 4););
      sendValueUpdate8(VALUE_UPDATE_ID_THROTTLEPERC, MMR_BUFFER_ReadUint16(msg->payload, 6, MMR_ENCODING_LITTLE_ENDIAN) / 100);
      break;

    case MMR_CAN_MESSAGE_ID_ECU_TEMPERATURES:
      sendValueUpdate8(VALUE_UPDATE_ID_OILTEMP, MMR_BUFFER_ReadByte(msg->payload, 0) - 40);
      sendValueUpdate8(VALUE_UPDATE_ID_WATERTEMP, MMR_BUFFER_ReadByte(msg->payload, 2) - 40);
      break;

    case MMR_CAN_MESSAGE_ID_ECU_PRESSURES:
      sendValueUpdateFloat(VALUE_UPDATE_ID_OILPRESS, MMR_BUFFER_ReadFloat(msg->payload, 0, MMR_ENCODING_LITTLE_ENDIAN) / 20.0f);
      break;

    case MMR_CAN_MESSAGE_ID_ECU_BRAKE_PRESSURES:
      sendValueUpdateFloat(VALUE_UPDATE_ID_BRAKEPRESSFRONT, (0.005f) * MMR_BUFFER_ReadUint16(msg->payload, 2, MMR_ENCODING_LITTLE_ENDIAN));
      sendValueUpdateFloat(VALUE_UPDATE_ID_BRAKEPRESSREAR, (0.005f) * MMR_BUFFER_ReadUint16(msg->payload, 0, MMR_ENCODING_LITTLE_ENDIAN));
      break;

    case MMR_CAN_MESSAGE_ID_ECU_ENGINE_FN2:
      sendValueUpdateFloat(VALUE_UPDATE_ID_VOLTAGE12V, (float)MMR_BUFFER_ReadUint16(msg->payload, 0, MMR_ENCODING_LITTLE_ENDIAN) / 1000.0f);
      break;

    case MMR_CAN_MESSAGE_ID_ECU_LAUNCH_CONTROL_ACK:
      bool launchControlSet = 1 == (MMR_BUFFER_ReadByte(msg->payload, 0) & 0x1);
      carState.launchControlState = launchControlSet? MMR_LAUNCH_CONTROL_SET : MMR_LAUNCH_CONTROL_NOT_SET;
      sendValueUpdateBool(VALUE_UPDATE_ID_LC, launchControlSet);
      break;

    case MMR_CAN_MESSAGE_ID_CS_CLUTCH_PULL_OK:
      sendValueUpdate8(VALUE_UPDATE_ID_CLT, true);
      break;

    case MMR_CAN_MESSAGE_ID_CS_CLUTCH_RELEASE_OK:
      sendValueUpdate8(VALUE_UPDATE_ID_CLT, false);
      break;

    case MMR_CAN_MESSAGE_ID_ORIN_TEMPERATURE:
      sendValueUpdateFloat(VALUE_UPDATE_ID_ORINTEMP, MMR_BUFFER_ReadFloat(msg->payload, 0, MMR_ENCODING_LITTLE_ENDIAN));
      break;

    case MMR_CAN_MESSAGE_ID_24v:
      sendValueUpdateFloat(VALUE_UPDATE_ID_VOLTAGE24V, MMR_BUFFER_ReadFloat(msg->payload, 0, MMR_ENCODING_LITTLE_ENDIAN));
      break;

    default:
      return;
  }
}

void task_process_can_rx() {
  static uint8_t rxBuf[8];

  MmrCanMessage rxMsg;
  MMR_CAN_MESSAGE_SetPayload(&rxMsg, rxBuf, 8);
  
  int pendingCanMsgs = MMR_CAN_GetPendingMessages(&mcp2515);
  
  for (int i = 0; i < pendingCanMsgs; ++i) {
    if (MMR_CAN_Receive(&mcp2515, &rxMsg))
      process_single_can_message(&rxMsg);
    else
      userMessage("WARN: Message reception failed.");
  }
}

void task_process_buttons() {
#define IS_JUST_PRESSED(x) MMR_BUTTON_Read(&x.mmr_button) == MMR_BUTTON_JUST_PRESSED

  if (IS_JUST_PRESSED(SHIFT_UP_BTN)) {
    ecu_task_request(ECU_Task_ShiftingUp);
  }
  if (IS_JUST_PRESSED(SHIFT_DOWN_BTN)) {
    ecu_task_request(ECU_Task_ShiftingDown);
  }
  if (IS_JUST_PRESSED(SHIFT_NTRL_BTN)) {
    ecu_task_request(ECU_Task_ShiftingNtrl);
  }
  if (IS_JUST_PRESSED(SET_LAUNCHCTRL_BTN)) {
    ecu_task_request(carState.launchControlState == MMR_LAUNCH_CONTROL_SET? ECU_Task_UnsetLaunchCtrl : ECU_Task_SetLaunchCtrl);
  }
  if (IS_JUST_PRESSED(MISSION_MANUAL_BTN)) {
    mission_request(MMR_MISSION_MANUAL);
  }
}

void task_send_missionrequest() {
  if (isSwitchingMission) {
    MmrTaskResult result = RepeatAsync(&sendMissionRequestRepeatAsync);
    if (result != MMR_TASK_PENDING) {
      if (result == MMR_TASK_COMPLETED)
        userMessage("INFO: Mission switched.");
      else
        userMessage("WARN: Mission switch failed.");
      isSwitchingMission = false;
    }
  }
}

void task_send_resopmode() {
  if (isSendingResOpMode) {
    MmrTaskResult result = RepeatAsync(&sendResOpModeRepeatAsync);
    if (result != MMR_TASK_PENDING) {
      if (result == MMR_TASK_COMPLETED)
        userMessage("INFO: Sent res operational mode.");
      else
        userMessage("WARN: RES operational mode transmission failed.");
      isSwitchingMission = false;
    }
  }
}


void configuration() {
  // Initialize the MMR libraries
  userMessage("INFO: Initialization...");

  MMR_SetTickProvider(HAL_GetTick);

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
}


void userDefaultTask() {
  
  configuration();

  userMessage("INFO: Running.");

  while (true) {
    task_process_can_rx();
    task_process_gui_messages_rx();
    task_process_buttons();

    task_run_ecu_tasks();
    task_send_missionrequest();
    task_send_resopmode();
  }
}


