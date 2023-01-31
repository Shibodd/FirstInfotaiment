#include <gui/missionselect_screen/MissionSelectView.hpp>
#include "main.h"

MissionSelectView::MissionSelectView()
{

}

void MissionSelectView::startManualMission() {
    presenter->requestMission(MISSION_MANUAL);
}

void MissionSelectView::startTrackdriveMission() {
    presenter->requestMission(MISSION_TRACKDRIVE);
}

void MissionSelectView::startAccelerationMission() {
    presenter->requestMission(MISSION_ACCELERATION);
}

void MissionSelectView::setupScreen()
{
    MissionSelectViewBase::setupScreen();
}

void MissionSelectView::tearDownScreen()
{
    MissionSelectViewBase::tearDownScreen();
}
