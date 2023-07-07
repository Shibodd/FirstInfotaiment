/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef DRIVERSCREENVIEWBASE_HPP
#define DRIVERSCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/driverscreen_screen/DriverScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class DriverScreenViewBase : public touchgfx::View<DriverScreenPresenter>
{
public:
    DriverScreenViewBase();
    virtual ~DriverScreenViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::TextArea txtTmot_1;
    touchgfx::Button btnPrevPage;
    touchgfx::Button btnNextPage;
    touchgfx::BoxWithBorder boxRpm;
    touchgfx::BoxWithBorder boxLC;
    touchgfx::BoxWithBorder boxTmot;
    touchgfx::BoxWithBorder boxCLT;
    touchgfx::BoxWithBorder boxToil;
    touchgfx::BoxWithBorder boxRES;
    touchgfx::BoxWithBorder boxTorin;
    touchgfx::BoxWithBorder boxBat24;
    touchgfx::BoxWithBorder boxBat12;
    touchgfx::BoxWithBorder boxPoil;
    touchgfx::BoxWithBorder boxPfuel;
    touchgfx::BoxWithBorder boxTPS;
    touchgfx::BoxWithBorder boxPbrake;
    touchgfx::BoxWithBorder boxLap;
    touchgfx::BoxWithBorder boxSpeed;
    touchgfx::BoxWithBorder boxGear;
    touchgfx::TextAreaWithOneWildcard txtGear;
    touchgfx::TextAreaWithOneWildcard txtRpm;
    touchgfx::TextAreaWithOneWildcard txtTmot;
    touchgfx::TextArea labelLC;
    touchgfx::TextArea labelRES;
    touchgfx::TextArea labelCLT;
    touchgfx::TextArea labelTmot;
    touchgfx::TextArea labelToil;
    touchgfx::TextArea labelTorin;
    touchgfx::TextArea labelBat12;
    touchgfx::TextArea labelTorin_1_1;
    touchgfx::TextArea labelPoil;
    touchgfx::TextArea labelTPS;
    touchgfx::TextArea labelPbrake;
    touchgfx::TextArea labelPfuel;
    touchgfx::TextAreaWithOneWildcard txtPoil;
    touchgfx::TextAreaWithOneWildcard txtTPS;
    touchgfx::TextAreaWithOneWildcard txtPbrake;
    touchgfx::TextAreaWithOneWildcard txtBat24;
    touchgfx::TextAreaWithOneWildcard txtPfuel;
    touchgfx::TextAreaWithOneWildcard txtBat12;
    touchgfx::TextAreaWithOneWildcard txtToil;
    touchgfx::TextAreaWithOneWildcard txtTorin;
    touchgfx::TextAreaWithOneWildcard txtLap;
    touchgfx::TextAreaWithOneWildcard txtSpeed;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TXTGEAR_SIZE = 2;
    touchgfx::Unicode::UnicodeChar txtGearBuffer[TXTGEAR_SIZE];
    static const uint16_t TXTRPM_SIZE = 6;
    touchgfx::Unicode::UnicodeChar txtRpmBuffer[TXTRPM_SIZE];
    static const uint16_t TXTTMOT_SIZE = 4;
    touchgfx::Unicode::UnicodeChar txtTmotBuffer[TXTTMOT_SIZE];
    static const uint16_t TXTPOIL_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txtPoilBuffer[TXTPOIL_SIZE];
    static const uint16_t TXTTPS_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtTPSBuffer[TXTTPS_SIZE];
    static const uint16_t TXTPBRAKE_SIZE = 4;
    touchgfx::Unicode::UnicodeChar txtPbrakeBuffer[TXTPBRAKE_SIZE];
    static const uint16_t TXTBAT24_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txtBat24Buffer[TXTBAT24_SIZE];
    static const uint16_t TXTPFUEL_SIZE = 4;
    touchgfx::Unicode::UnicodeChar txtPfuelBuffer[TXTPFUEL_SIZE];
    static const uint16_t TXTBAT12_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txtBat12Buffer[TXTBAT12_SIZE];
    static const uint16_t TXTTOIL_SIZE = 4;
    touchgfx::Unicode::UnicodeChar txtToilBuffer[TXTTOIL_SIZE];
    static const uint16_t TXTTORIN_SIZE = 4;
    touchgfx::Unicode::UnicodeChar txtTorinBuffer[TXTTORIN_SIZE];
    static const uint16_t TXTLAP_SIZE = 2;
    touchgfx::Unicode::UnicodeChar txtLapBuffer[TXTLAP_SIZE];
    static const uint16_t TXTSPEED_SIZE = 8;
    touchgfx::Unicode::UnicodeChar txtSpeedBuffer[TXTSPEED_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<DriverScreenViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // DRIVERSCREENVIEWBASE_HPP
