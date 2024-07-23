/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/driverscreen_screen/DriverScreenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

DriverScreenViewBase::DriverScreenViewBase() :
    buttonCallback(this, &DriverScreenViewBase::buttonCallbackHandler)
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    txtTmot_1.setPosition(531, 384, 133, 73);
    txtTmot_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtTmot_1.setLinespacing(0);
    txtTmot_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_DCFN));
    add(txtTmot_1);

    btnPrevPage.setXY(17, 415);
    btnPrevPage.setBitmaps(touchgfx::Bitmap(BITMAP_BTN_PREV_ID), touchgfx::Bitmap(BITMAP_BTN_PREV_ID));
    btnPrevPage.setAction(buttonCallback);
    add(btnPrevPage);

    btnNextPage.setXY(735, 415);
    btnNextPage.setBitmaps(touchgfx::Bitmap(BITMAP_BTN_NEXT_ID), touchgfx::Bitmap(BITMAP_BTN_NEXT_ID));
    btnNextPage.setAction(buttonCallback);
    add(btnNextPage);

    boxRpm.setPosition(1, 0, 266, 120);
    boxRpm.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxRpm.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxRpm.setBorderSize(2);
    add(boxRpm);

    boxLC.setPosition(531, 360, 133, 120);
    boxLC.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxLC.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxLC.setBorderSize(2);
    add(boxLC);

    boxTmot.setPosition(134, 120, 133, 120);
    boxTmot.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxTmot.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxTmot.setBorderSize(2);
    add(boxTmot);

    boxCLT.setPosition(1, 240, 133, 120);
    boxCLT.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxCLT.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxCLT.setBorderSize(2);
    add(boxCLT);

    boxToil.setPosition(134, 240, 133, 120);
    boxToil.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxToil.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxToil.setBorderSize(2);
    add(boxToil);

    boxRES.setPosition(1, 120, 133, 120);
    boxRES.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxRES.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxRES.setBorderSize(2);
    add(boxRES);

    boxTorin.setPosition(134, 360, 133, 120);
    boxTorin.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxTorin.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxTorin.setBorderSize(2);
    add(boxTorin);

    boxBat24.setPosition(398, 360, 133, 120);
    boxBat24.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxBat24.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxBat24.setBorderSize(2);
    add(boxBat24);

    boxBat12.setPosition(267, 360, 131, 120);
    boxBat12.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxBat12.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxBat12.setBorderSize(2);
    add(boxBat12);

    boxPoil.setPosition(531, 120, 133, 120);
    boxPoil.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxPoil.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxPoil.setBorderSize(2);
    add(boxPoil);

    boxPfuel.setPosition(531, 240, 133, 120);
    boxPfuel.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxPfuel.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxPfuel.setBorderSize(2);
    add(boxPfuel);

    boxTPS.setPosition(663, 120, 137, 120);
    boxTPS.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxTPS.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxTPS.setBorderSize(2);
    add(boxTPS);

    boxPbrake.setPosition(664, 240, 136, 120);
    boxPbrake.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxPbrake.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxPbrake.setBorderSize(2);
    add(boxPbrake);

    boxLap.setPosition(267, 0, 265, 120);
    boxLap.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxLap.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxLap.setBorderSize(2);
    add(boxLap);

    boxSpeed.setPosition(531, 0, 269, 120);
    boxSpeed.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxSpeed.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxSpeed.setBorderSize(2);
    add(boxSpeed);

    boxGear.setPosition(267, 120, 265, 240);
    boxGear.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxGear.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxGear.setBorderSize(2);
    add(boxGear);

    txtGear.setPosition(267, 120, 265, 240);
    txtGear.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtGear.setLinespacing(0);
    Unicode::snprintf(txtGearBuffer, TXTGEAR_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_BNQX).getText());
    txtGear.setWildcard(txtGearBuffer);
    txtGear.setTypedText(touchgfx::TypedText(T___SINGLEUSE_0O7B));
    add(txtGear);

    txtRpm.setPosition(1, 24, 266, 72);
    txtRpm.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtRpm.setLinespacing(0);
    Unicode::snprintf(txtRpmBuffer, TXTRPM_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_2FOI).getText());
    txtRpm.setWildcard(txtRpmBuffer);
    txtRpm.setTypedText(touchgfx::TypedText(T___SINGLEUSE_YH8M));
    add(txtRpm);

    txtTmot.setPosition(134, 167, 133, 73);
    txtTmot.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtTmot.setLinespacing(0);
    Unicode::snprintf(txtTmotBuffer, TXTTMOT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_HO5R).getText());
    txtTmot.setWildcard(txtTmotBuffer);
    txtTmot.setTypedText(touchgfx::TypedText(T___SINGLEUSE_73JB));
    add(txtTmot);

    labelLC.setPosition(531, 384, 133, 73);
    labelLC.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    labelLC.setLinespacing(0);
    labelLC.setTypedText(touchgfx::TypedText(T___SINGLEUSE_43VM));
    add(labelLC);

    labelRES.setPosition(1, 146, 131, 69);
    labelRES.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    labelRES.setLinespacing(0);
    labelRES.setTypedText(touchgfx::TypedText(T___SINGLEUSE_A8DL));
    add(labelRES);

    labelCLT.setPosition(1, 264, 132, 73);
    labelCLT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    labelCLT.setLinespacing(0);
    labelCLT.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Y1TQ));
    add(labelCLT);

    labelTmot.setPosition(134, 130, 133, 37);
    labelTmot.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    labelTmot.setLinespacing(0);
    labelTmot.setTypedText(touchgfx::TypedText(T___SINGLEUSE_S2KY));
    add(labelTmot);

    labelToil.setPosition(134, 250, 133, 37);
    labelToil.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    labelToil.setLinespacing(0);
    labelToil.setTypedText(touchgfx::TypedText(T___SINGLEUSE_2Q01));
    add(labelToil);

    labelTorin.setPosition(134, 367, 133, 37);
    labelTorin.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    labelTorin.setLinespacing(0);
    labelTorin.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8VFR));
    add(labelTorin);

    labelBat12.setPosition(268, 370, 130, 37);
    labelBat12.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    labelBat12.setLinespacing(0);
    labelBat12.setTypedText(touchgfx::TypedText(T___SINGLEUSE_DE5T));
    add(labelBat12);

    labelTorin_1_1.setPosition(399, 370, 130, 37);
    labelTorin_1_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    labelTorin_1_1.setLinespacing(0);
    labelTorin_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_6T5M));
    add(labelTorin_1_1);

    labelPoil.setPosition(532, 130, 132, 37);
    labelPoil.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    labelPoil.setLinespacing(0);
    labelPoil.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8R8S));
    add(labelPoil);

    labelTPS.setPosition(664, 130, 136, 37);
    labelTPS.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    labelTPS.setLinespacing(0);
    labelTPS.setTypedText(touchgfx::TypedText(T___SINGLEUSE_OXBY));
    add(labelTPS);

    labelPbrake.setPosition(665, 250, 131, 37);
    labelPbrake.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    labelPbrake.setLinespacing(0);
    labelPbrake.setTypedText(touchgfx::TypedText(T___SINGLEUSE_7E8Q));
    add(labelPbrake);

    labelPfuel.setPosition(532, 250, 131, 37);
    labelPfuel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    labelPfuel.setLinespacing(0);
    labelPfuel.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Z9U2));
    add(labelPfuel);

    txtPoil.setPosition(532, 167, 131, 73);
    txtPoil.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtPoil.setLinespacing(0);
    Unicode::snprintf(txtPoilBuffer, TXTPOIL_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_TP9G).getText());
    txtPoil.setWildcard(txtPoilBuffer);
    txtPoil.setTypedText(touchgfx::TypedText(T___SINGLEUSE_E4IL));
    add(txtPoil);

    txtTPS.setPosition(664, 167, 137, 73);
    txtTPS.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtTPS.setLinespacing(0);
    Unicode::snprintf(txtTPSBuffer, TXTTPS_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_2VKQ).getText());
    txtTPS.setWildcard(txtTPSBuffer);
    txtTPS.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QBHD));
    add(txtTPS);

    txtPbrake.setPosition(664, 287, 136, 73);
    txtPbrake.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtPbrake.setLinespacing(0);
    Unicode::snprintf(txtPbrakeBuffer, TXTPBRAKE_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_5Z8O).getText());
    txtPbrake.setWildcard(txtPbrakeBuffer);
    txtPbrake.setTypedText(touchgfx::TypedText(T___SINGLEUSE_IEE9));
    add(txtPbrake);

    txtBat24.setPosition(399, 407, 130, 73);
    txtBat24.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtBat24.setLinespacing(0);
    Unicode::snprintf(txtBat24Buffer, TXTBAT24_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_1E1Q).getText());
    txtBat24.setWildcard(txtBat24Buffer);
    txtBat24.setTypedText(touchgfx::TypedText(T___SINGLEUSE_BB62));
    add(txtBat24);

    txtPfuel.setPosition(533, 287, 131, 73);
    txtPfuel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtPfuel.setLinespacing(0);
    Unicode::snprintf(txtPfuelBuffer, TXTPFUEL_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_AJ0J).getText());
    txtPfuel.setWildcard(txtPfuelBuffer);
    txtPfuel.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Q9H4));
    add(txtPfuel);

    txtBat12.setPosition(267, 407, 131, 73);
    txtBat12.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtBat12.setLinespacing(0);
    Unicode::snprintf(txtBat12Buffer, TXTBAT12_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_KOX0).getText());
    txtBat12.setWildcard(txtBat12Buffer);
    txtBat12.setTypedText(touchgfx::TypedText(T___SINGLEUSE_1UNR));
    add(txtBat12);

    txtToil.setPosition(134, 287, 133, 73);
    txtToil.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtToil.setLinespacing(0);
    Unicode::snprintf(txtToilBuffer, TXTTOIL_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_CUPH).getText());
    txtToil.setWildcard(txtToilBuffer);
    txtToil.setTypedText(touchgfx::TypedText(T___SINGLEUSE_BID7));
    add(txtToil);

    txtTorin.setPosition(134, 404, 133, 76);
    txtTorin.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtTorin.setLinespacing(0);
    Unicode::snprintf(txtTorinBuffer, TXTTORIN_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_IM6N).getText());
    txtTorin.setWildcard(txtTorinBuffer);
    txtTorin.setTypedText(touchgfx::TypedText(T___SINGLEUSE_T9US));
    add(txtTorin);

    txtLap.setPosition(267, 24, 264, 72);
    txtLap.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtLap.setLinespacing(0);
    Unicode::snprintf(txtLapBuffer, TXTLAP_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_1QOJ).getText());
    txtLap.setWildcard(txtLapBuffer);
    txtLap.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QZ30));
    add(txtLap);

    txtSpeed.setPosition(532, 24, 268, 72);
    txtSpeed.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtSpeed.setLinespacing(0);
    Unicode::snprintf(txtSpeedBuffer, TXTSPEED_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_AHJH).getText());
    txtSpeed.setWildcard(txtSpeedBuffer);
    txtSpeed.setTypedText(touchgfx::TypedText(T___SINGLEUSE_0URK));
    add(txtSpeed);
}

DriverScreenViewBase::~DriverScreenViewBase()
{

}

void DriverScreenViewBase::setupScreen()
{

}

void DriverScreenViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &btnNextPage)
    {
        //fromDriverScreenToMainInfotaiment
        //When btnNextPage clicked change screen to MainInfotaiment
        //Go to MainInfotaiment with screen transition towards East
        application().gotoMainInfotaimentScreenSlideTransitionEast();
    }
    if (&src == &btnPrevPage)
    {
        //fromDriverScreenToLogging
        //When btnPrevPage clicked change screen to Logging
        //Go to Logging with screen transition towards West
        application().gotoLoggingScreenSlideTransitionWest();
    }
}
