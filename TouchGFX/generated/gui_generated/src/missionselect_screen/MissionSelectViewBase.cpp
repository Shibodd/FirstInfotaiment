/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/missionselect_screen/MissionSelectViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

MissionSelectViewBase::MissionSelectViewBase() :
    buttonCallback(this, &MissionSelectViewBase::buttonCallbackHandler),
    flexButtonCallback(this, &MissionSelectViewBase::flexButtonCallbackHandler)
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    btnNextPage.setXY(735, 415);
    btnNextPage.setBitmaps(touchgfx::Bitmap(BITMAP_BTN_NEXT_ID), touchgfx::Bitmap(BITMAP_BTN_NEXT_ID));
    btnNextPage.setAction(buttonCallback);
    add(btnNextPage);

    btnPrevPage.setXY(17, 415);
    btnPrevPage.setBitmaps(touchgfx::Bitmap(BITMAP_BTN_PREV_ID), touchgfx::Bitmap(BITMAP_BTN_PREV_ID));
    btnPrevPage.setAction(buttonCallback);
    add(btnPrevPage);

    labelSelectMission.setXY(293, 17);
    labelSelectMission.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    labelSelectMission.setLinespacing(0);
    labelSelectMission.setTypedText(touchgfx::TypedText(T___SINGLEUSE_U2AM));
    add(labelSelectMission);

    chassisResetBtn.setBoxWithBorderPosition(0, 0, 214, 299);
    chassisResetBtn.setBorderSize(5);
    chassisResetBtn.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(58, 121, 153), touchgfx::Color::getColorFromRGB(0, 119, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    chassisResetBtn.setText(TypedText(T___SINGLEUSE_5MAQ));
    chassisResetBtn.setTextPosition(0, 93, 214, 299);
    chassisResetBtn.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255));
    chassisResetBtn.setAction(flexButtonCallback);
    chassisResetBtn.setPosition(17, 84, 214, 299);
    add(chassisResetBtn);

    idleBtn.setXY(270, 84);
    idleBtn.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_PRESSED_ID));
    idleBtn.setLabelText(touchgfx::TypedText(T___SINGLEUSE_W8G5));
    idleBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    idleBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    idleBtn.setAction(buttonCallback);
    add(idleBtn);

    trackdriveBtn.setXY(532, 84);
    trackdriveBtn.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_PRESSED_ID));
    trackdriveBtn.setLabelText(touchgfx::TypedText(T___SINGLEUSE_9VBP));
    trackdriveBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    trackdriveBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    trackdriveBtn.setAction(buttonCallback);
    add(trackdriveBtn);

    ebsTestBtn.setXY(532, 164);
    ebsTestBtn.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_PRESSED_ID));
    ebsTestBtn.setLabelText(touchgfx::TypedText(T___SINGLEUSE_4TAP));
    ebsTestBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    ebsTestBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    ebsTestBtn.setAction(buttonCallback);
    add(ebsTestBtn);

    inspectionBtn.setXY(532, 244);
    inspectionBtn.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_PRESSED_ID));
    inspectionBtn.setLabelText(touchgfx::TypedText(T___SINGLEUSE_FFJ8));
    inspectionBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    inspectionBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    inspectionBtn.setAction(buttonCallback);
    add(inspectionBtn);

    manualBtn.setXY(532, 323);
    manualBtn.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_PRESSED_ID));
    manualBtn.setLabelText(touchgfx::TypedText(T___SINGLEUSE_33YC));
    manualBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    manualBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    manualBtn.setAction(buttonCallback);
    add(manualBtn);

    debugBtn.setXY(400, 405);
    debugBtn.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_PRESSED_ID));
    debugBtn.setLabelText(touchgfx::TypedText(T___SINGLEUSE_9QUA));
    debugBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    debugBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    debugBtn.setAction(buttonCallback);
    add(debugBtn);

    accelerationBtn.setXY(270, 164);
    accelerationBtn.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_PRESSED_ID));
    accelerationBtn.setLabelText(touchgfx::TypedText(T___SINGLEUSE_O6Z0));
    accelerationBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    accelerationBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    accelerationBtn.setAction(buttonCallback);
    add(accelerationBtn);

    skidpadBtn.setXY(270, 244);
    skidpadBtn.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_PRESSED_ID));
    skidpadBtn.setLabelText(touchgfx::TypedText(T___SINGLEUSE_55VW));
    skidpadBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    skidpadBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    skidpadBtn.setAction(buttonCallback);
    add(skidpadBtn);

    autocrossBtn.setXY(270, 323);
    autocrossBtn.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_SMALL_ROUNDED_PRESSED_ID));
    autocrossBtn.setLabelText(touchgfx::TypedText(T___SINGLEUSE_VKZX));
    autocrossBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    autocrossBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    autocrossBtn.setAction(buttonCallback);
    add(autocrossBtn);
}

MissionSelectViewBase::~MissionSelectViewBase()
{

}

void MissionSelectViewBase::setupScreen()
{

}

void MissionSelectViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &btnNextPage)
    {
        //fromMissionSelectToCompetitionScreen
        //When btnNextPage clicked change screen to CompetitionScreen
        //Go to CompetitionScreen with screen transition towards East
        application().gotoCompetitionScreenScreenSlideTransitionEast();
    }
    if (&src == &idleBtn)
    {
        //IdleMission
        //When idleBtn clicked call virtual function
        //Call onIdleBtnClicked
        onIdleBtnClicked();
    }
    if (&src == &accelerationBtn)
    {
        //AccelerationMission
        //When accelerationBtn clicked call virtual function
        //Call onAccelerationBtnClicked
        onAccelerationBtnClicked();
    }
    if (&src == &skidpadBtn)
    {
        //SkidpadMission
        //When skidpadBtn clicked call virtual function
        //Call onSkidpadBtnClicked
        onSkidpadBtnClicked();
    }
    if (&src == &autocrossBtn)
    {
        //AutocrossMission
        //When autocrossBtn clicked call virtual function
        //Call onAutocrossBtnClicked
        onAutocrossBtnClicked();
    }
    if (&src == &trackdriveBtn)
    {
        //TrackdriveMission
        //When trackdriveBtn clicked call virtual function
        //Call onTrackdriveBtnClicked
        onTrackdriveBtnClicked();
    }
    if (&src == &ebsTestBtn)
    {
        //EbtTestMission
        //When ebsTestBtn clicked call virtual function
        //Call onEbsTestBtnClicked
        onEbsTestBtnClicked();
    }
    if (&src == &inspectionBtn)
    {
        //InspectionMission
        //When inspectionBtn clicked call virtual function
        //Call onInspectionBtnClicked
        onInspectionBtnClicked();
    }
    if (&src == &manualBtn)
    {
        //ManualMission
        //When manualBtn clicked call virtual function
        //Call onManualBtnClicked
        onManualBtnClicked();
    }
    if (&src == &debugBtn)
    {
        //DebugMission
        //When debugBtn clicked call virtual function
        //Call onDebugBtnClicked
        onDebugBtnClicked();
    }
    if (&src == &btnPrevPage)
    {
        //fromMissionSelectToMainInfotaiment
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
