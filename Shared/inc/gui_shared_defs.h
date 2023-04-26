#ifndef GUI_SHARED_DEFS_H
#define GUI_SHARED_DEFS_H

#include <stdint.h>

typedef struct {
	uint8_t speed;
	uint8_t gear;
	uint16_t rpm;
	uint8_t T_water;
	uint8_t T_oil;
	uint8_t throttle_perc;
	uint8_t brake_perc;
	float P_oil;
	int RES;
	bool LC;
	bool CLT;
	float battery_v;
	/* TODO: String variables */
} displayInfo;

typedef enum {
  MMR_MISSION_ACCELERATION = 0,
  MMR_MISSION_SKIDPAD = 1,
  MMR_MISSION_TRACK_DRIVE = 2,
  MMR_MISSION_EBS_TEST = 3,
  MMR_MISSION_INSPECTION = 4,
  MMR_MISSION_AUTOCROSS = 5,
  MMR_MISSION_DEBUG = 6,
  MMR_MISSION_MANUAL = 7,
  MMR_MISSION_IDLE = 8,
} MmrMission;

typedef struct {
  MmrMission missionType;
} guiToMainMsg;

#endif // GUI_SHARED_DEFS_H