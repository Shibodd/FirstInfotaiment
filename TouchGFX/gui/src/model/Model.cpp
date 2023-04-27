#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifdef SIMULATOR
#include <stdio.h>
#endif // SIMULATOR


#ifndef SIMULATOR
#include "cmsis_os.h"
#include "main.h"

extern osMessageQueueId_t dbgMsgQueue;
extern osMessageQueueId_t guiToMainMsgQueue;
extern osMessageQueueId_t mainToGuiMsgQueue;
#endif // NOT SIMULATOR

displayInfo info;

Model::Model() : modelListener(0)
{
	dbgMessage = nullptr;
}



void Model::tick()
{
#ifndef SIMULATOR
	osStatus_t status;
	status = osMessageQueueGet(mainToGuiMsgQueue, &info, NULL, 0);
	if (status == osOK)
	{
		gear = info.gear;
		speed = info.speed;
		rpm = info.rpm;

		T_water = info.T_water;
		T_oil = info.T_oil;
		P_oil = info.P_oil;

		throttle_perc = info.throttle_perc;
		brake_perc = info.brake_perc;

		RES = info.RES;
		LC = info.LC;
		CLT = info.CLT;

		battery_v = info.battery_v;

		/* TODO: String variables */

		modelListener->infoChanged();
	}

	status = osMessageQueueGet(dbgMsgQueue, &dbgMessage, NULL, 0);
	if (status == osOK)
		modelListener->debugMessageChanged();
#endif // NOT SIMULATOR
}


void Model::requestMission(MmrMission missionType) {
#ifndef SIMULATOR
	guiToMainMsg msg {
		.missionType = missionType
	};

	osMessageQueuePut(guiToMainMsgQueue, &msg, 0, 0);
#endif // NOT SIMULATOR

#ifdef SIMULATOR
	static char buf[32];
	snprintf(buf, 32, "Mission requested: %d", missionType);
	dbgMessage = buf;
	modelListener->debugMessageChanged();
#endif // SIMULATOR
}
