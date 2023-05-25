#ifndef GUI_SHARED_DEFS_H
#define GUI_SHARED_DEFS_H

#include <stdint.h>
#include <missions.h>

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

typedef struct {
  MmrMission missionType;
} guiToMainMsg;

#endif // GUI_SHARED_DEFS_H
