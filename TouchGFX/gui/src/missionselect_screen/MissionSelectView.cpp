#include <gui/missionselect_screen/MissionSelectView.hpp>
#include "gui_shared_defs.h"

MissionSelectView::MissionSelectView()
{

}

void MissionSelectView::startManualMission() {
    presenter->requestMission(MMR_MISSION_MANUAL);
}

void MissionSelectView::startTrackdriveMission() {
    presenter->requestMission(MMR_MISSION_TRACK_DRIVE);
}

void MissionSelectView::startAccelerationMission() {
    presenter->requestMission(MMR_MISSION_ACCELERATION);
}

void MissionSelectView::setupScreen()
{
    MissionSelectViewBase::setupScreen();
}

void MissionSelectView::tearDownScreen()
{
    MissionSelectViewBase::tearDownScreen();
}
