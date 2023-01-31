#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "cmsis_os.h"
#include "main.h"

extern osMessageQueueId_t guiToMainMsgQueue;
extern osMessageQueueId_t mainToGuiMsgQueue;

displayInfo info;

Model::Model() : modelListener(0)
{
}

void Model::tick()
{
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
}


void Model::requestMission(MissionType missionType) {
	guiToMainMsg msg {
		.missionType = missionType
	};

	osMessageQueuePut(guiToMainMsgQueue, &missionType, 0, 0);
}