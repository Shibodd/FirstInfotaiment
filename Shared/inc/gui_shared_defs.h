#ifndef GUI_SHARED_DEFS_H
#define GUI_SHARED_DEFS_H

#include <stdint.h>
#include <missions.h>

// VALUE UPDATE MESSAGE
typedef enum {
	VALUE_UPDATE_ID_SPEED, // uint16_t
	VALUE_UPDATE_ID_GEAR, // uint8_t
	VALUE_UPDATE_ID_RPM, // uint16_t

	VALUE_UPDATE_ID_RES, // bool
	VALUE_UPDATE_ID_LC, // bool
	VALUE_UPDATE_ID_CLT, // bool

	VALUE_UPDATE_ID_WATERTEMP, // uint8_t
	VALUE_UPDATE_ID_OILTEMP, // uint8_t
	VALUE_UPDATE_ID_OILPRESS, // float

	VALUE_UPDATE_ID_THROTTLEPERC, // uint8_t
	VALUE_UPDATE_ID_BRAKEPRESSFRONT, // float 
	VALUE_UPDATE_ID_BRAKEPRESSREAR, // float

	VALUE_UPDATE_ID_ORINTEMP, // float
	VALUE_UPDATE_ID_VOLTAGE24V, // float
	VALUE_UPDATE_ID_VOLTAGE12V // float
} ValueUpdateId;

#define VALUE_MESSAGE_MAX_SIZE sizeof(uint32_t)
typedef struct {
  ValueUpdateId id;
  uint8_t value[VALUE_MESSAGE_MAX_SIZE];
} valueUpdateMessage;


// GUI TO MAIN MESSAGES
typedef enum {
  GUI_TO_MAIN_MSG_MISSIONSELECT,
  GUI_TO_MAIN_MSG_SETRESOPMODE
} GuiToMainMsgType;

typedef struct {
  GuiToMainMsgType type;
  union {
  	MmrMission selectedMission;
  } content;
} guiToMainMsg;

#endif // GUI_SHARED_DEFS_H
