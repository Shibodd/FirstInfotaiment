/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/missionselect_screen/MissionSelectViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

MissionSelectViewBase::MissionSelectViewBase() :
    updateItemCallback(this, &MissionSelectViewBase::updateItemCallbackHandler),
    buttonCallback(this, &MissionSelectViewBase::buttonCallbackHandler),
    flexButtonCallback(this, &MissionSelectViewBase::flexButtonCallbackHandler)
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    btnPrevPage.setXY(735, 415);
    btnPrevPage.setBitmaps(touchgfx::Bitmap(BITMAP_BTN_PREV_ID), touchgfx::Bitmap(BITMAP_BTN_PREV_ID));
    btnPrevPage.setAction(buttonCallback);
    add(btnPrevPage);

    labelSelectMission.setXY(258, 17);
    labelSelectMission.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    labelSelectMission.setLinespacing(0);
    labelSelectMission.setTypedText(touchgfx::TypedText(T___SINGLEUSE_U2AM));
    add(labelSelectMission);

    missionScrollList.setPosition(280, 76, 214, 377);
    missionScrollList.setHorizontal(false);
    missionScrollList.setCircular(false);
    missionScrollList.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    missionScrollList.setSwipeAcceleration(10);
    missionScrollList.setDragAcceleration(10);
    missionScrollList.setNumberOfItems(1);
    missionScrollList.setPadding(0, 0);
    missionScrollList.setSnapping(false);
    missionScrollList.setDrawableSize(36, 7);
    missionScrollList.setDrawables(missionScrollListListItems, updateItemCallback);
    add(missionScrollList);

    chassisResetBtn.setBoxWithBorderPosition(0, 0, 215, 241);
    chassisResetBtn.setBorderSize(5);
    chassisResetBtn.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(58, 121, 153), touchgfx::Color::getColorFromRGB(0, 119, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    chassisResetBtn.setText(TypedText(T___SINGLEUSE_5MAQ));
    chassisResetBtn.setTextPosition(0, 93, 215, 241);
    chassisResetBtn.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255));
    chassisResetBtn.setAction(flexButtonCallback);
    chassisResetBtn.setPosition(12, 41, 215, 241);
    add(chassisResetBtn);
}

MissionSelectViewBase::~MissionSelectViewBase()
{

}

void MissionSelectViewBase::setupScreen()
{
    missionScrollList.initialize();
    for (int i = 0; i < missionScrollListListItems.getNumberOfDrawables(); i++)
    {
        missionScrollListListItems[i].initialize();
    }
}

void MissionSelectViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &btnPrevPage)
    {
        //fromMissionSelectToLiveData
        //When btnPrevPage clicked change screen to MainInfotaiment
        //Go to MainInfotaiment with screen transition towards West
        application().gotoMainInfotaimentScreenSlideTransitionWest();
    }
}

void MissionSelectViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &chassisResetBtn)
    {
        //ChassisReset
        //When chassisResetBtn clicked call virtual function
        //Call onChassisResetClicked
        onChassisResetClicked();
    }
}

void MissionSelectViewBase::updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex)
{
    if (items == &missionScrollListListItems)
    {
        missionScrollListUpdateItem(missionScrollListListItems[containerIndex], itemIndex);
    }
}
