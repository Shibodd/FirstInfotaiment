#include <gui/missionselect_screen/MissionSelectView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "gui_shared_defs.h"

struct MissionInfo {
    MmrMission mission;
    TEXTS textId;

    /* Store a pointer to the container to call doClickAnimation because TouchGFX is pure garbage:

        There's no way to pass a click event from a ClickListener widget (e.g. Button)
        to the controls under it... In our case, a Button over a ScrollList
        prevents scrollListItemSelectedHandler from ever being called.
        Which means that the widget can't react on its own,
        for example to have a visible feedback on click.
        As a workaround, i made up this POS: i call item.doClickAnimation, which
        starts an animation on the background AnimatedImage. */
    missionBtnContainer* item;
};

MissionInfo MISSIONS[] = {
	{ MMR_MISSION_IDLE, T_MISSIONIDLE, nullptr },
	{ MMR_MISSION_ACCELERATION, T_MISSIONACCELERATION, nullptr },
	{ MMR_MISSION_SKIDPAD, T_MISSIONSKIDPAD, nullptr },
	{ MMR_MISSION_AUTOCROSS, T_MISSIONAUTOCROSS, nullptr },
	{ MMR_MISSION_TRACKDRIVE, T_MISSIONTRACKDRIVE, nullptr },
	{ MMR_MISSION_EBS_TEST, T_MISSIONEBSTEST, nullptr },
	{ MMR_MISSION_INSPECTION, T_MISSIONINSPECTION, nullptr },
	{ MMR_MISSION_MANUAL, T_MISSIONMANUAL, nullptr },
	{ MMR_MISSION_DEBUG, T_MISSIONDEBUG, nullptr },
};
constexpr int MISSION_COUNT = sizeof(MISSIONS) / sizeof(MissionInfo);

void MissionSelectView::scrollListItemSelectedHandler(int16_t itemSelected) {
    presenter->requestMission(MISSIONS[itemSelected].mission);
    MISSIONS[itemSelected].item->doClickAnimation();
}


void MissionSelectView::setupScreen()
{
    MissionSelectViewBase::setupScreen();
    missionScrollList.setNumberOfItems(MISSION_COUNT);
    missionScrollList.setItemSelectedCallback(scrollListItemSelectedCallback);
    missionScrollList.invalidate();
}

void MissionSelectView::missionScrollListUpdateItem(missionBtnContainer& item, int16_t itemIndex) {
    item.setText(MISSIONS[itemIndex].textId);
    MISSIONS[itemIndex].item = &item;
}



MissionSelectView::MissionSelectView()
    : scrollListItemSelectedCallback(this, &MissionSelectView::scrollListItemSelectedHandler)
{

}

void MissionSelectView::tearDownScreen()
{
    MissionSelectViewBase::tearDownScreen();
}
