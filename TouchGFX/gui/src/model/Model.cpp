#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

displayInfo info;

Model::Model() : modelListener(0)
{
	dbgMessage = nullptr;
}


#ifdef SIMULATOR
static int t;

void Model::tick() {
  // Some random data
  rpm = (t * 60) % 12000; 
  throttle_perc = (t + 50) % 100;
  frontBrakePerc = t % 100;
  rearBrakePerc = 100 - (t % 100);

  ++t;
  modelListener->infoChanged();
}

#else

#include "cmsis_os.h"
#include "main.h"

extern osMessageQueueId_t dbgMsgQueue;
extern osMessageQueueId_t guiToMainMsgQueue;
extern osMessageQueueId_t mainToGuiMsgQueue;

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

		rearBrakePerc = info.brakePressureRear * (100.0 / 160.0);
		frontBrakePerc = info.brakePressureFront * (100.0 / 160.0);

		/* TODO: String variables */

		modelListener->infoChanged();
	}

	status = osMessageQueueGet(dbgMsgQueue, &dbgMessage, NULL, 0);
	if (status == osOK)
		modelListener->debugMessageChanged();

}
#endif


#ifdef SIMULATOR
#include <stdio.h>

void Model::requestMission(MmrMission missionType) {
  static char buf[32];
  snprintf(buf, 32, "Mission requested: %d", missionType);
  dbgMessage = buf;
  modelListener->debugMessageChanged();
}

#else

void Model::requestMission(MmrMission missionType) {
  guiToMainMsg msg {
	  .missionType = missionType
  };

  osMessageQueuePut(guiToMainMsgQueue, &msg, 0, 0);
}
#endif
