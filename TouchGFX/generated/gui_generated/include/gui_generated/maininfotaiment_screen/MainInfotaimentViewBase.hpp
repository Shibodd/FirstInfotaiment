/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MAININFOTAIMENTVIEWBASE_HPP
#define MAININFOTAIMENTVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/maininfotaiment_screen/MainInfotaimentPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/containers/progress_indicators/BoxProgress.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/Button.hpp>

class MainInfotaimentViewBase : public touchgfx::View<MainInfotaimentPresenter>
{
public:
    MainInfotaimentViewBase();
    virtual ~MainInfotaimentViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::TextAreaWithOneWildcard txtGear;
    touchgfx::TextAreaWithOneWildcard txtSpeed;
    touchgfx::TextArea labelSpeed;
    touchgfx::Line line1;
    touchgfx::PainterRGB565 line1Painter;
    touchgfx::TextAreaWithOneWildcard txtRpm;
    touchgfx::TextArea labelRpm;
    touchgfx::BoxWithBorder boxThrottle;
    touchgfx::BoxWithBorder boxBrake;
    touchgfx::BoxProgress progressThrottle;
    touchgfx::BoxProgress progressBrakeFront;
    touchgfx::BoxWithBorder boxBrake_1;
    touchgfx::BoxProgress progressBrakeRear;
    touchgfx::BoxWithBorder boxRES;
    touchgfx::Line line1_1;
    touchgfx::PainterRGB565 line1_1Painter;
    touchgfx::Line line1_1_1;
    touchgfx::PainterRGB565 line1_1_1Painter;
    touchgfx::TextArea labelLapCounter;
    touchgfx::TextAreaWithOneWildcard txtLap;
    touchgfx::TextArea labelRES;
    touchgfx::BoxProgress progressRpmLow;
    touchgfx::BoxProgress progressRpmMed;
    touchgfx::BoxProgress progressRpmHigh;
    touchgfx::BoxWithBorder boxTWater;
    touchgfx::TextAreaWithOneWildcard txtTWater;
    touchgfx::BoxWithBorder boxTOil;
    touchgfx::BoxWithBorder boxPOil;
    touchgfx::TextAreaWithOneWildcard txtTOil;
    touchgfx::TextAreaWithOneWildcard txtPOil;
    touchgfx::BoxWithBorder boxLC;
    touchgfx::TextArea labelLC;
    touchgfx::BoxWithBorder boxClutch;
    touchgfx::TextArea labelClutch;
    touchgfx::ScalableImage scalableImage1;
    touchgfx::TextArea labelDS;
    touchgfx::Line line1_2;
    touchgfx::PainterRGB565 line1_2Painter;
    touchgfx::Line line1_2_1;
    touchgfx::PainterRGB565 line1_2_1Painter;
    touchgfx::BoxWithBorder boxDS;
    touchgfx::TextArea labelAS;
    touchgfx::BoxWithBorder boxAS;
    touchgfx::Line line1_2_2;
    touchgfx::PainterRGB565 line1_2_2Painter;
    touchgfx::BoxWithBorder boxAMI;
    touchgfx::Line line1_2_1_1_1;
    touchgfx::PainterRGB565 line1_2_1_1_1Painter;
    touchgfx::BoxWithBorder boxEBS;
    touchgfx::TextArea labelAS_1;
    touchgfx::TextArea labelAS_2;
    touchgfx::TextAreaWithOneWildcard txtDS;
    touchgfx::TextAreaWithOneWildcard txtAS;
    touchgfx::TextAreaWithOneWildcard txtAMI;
    touchgfx::TextAreaWithOneWildcard txtEBS;
    touchgfx::BoxWithBorder boxBattery_V;
    touchgfx::TextAreaWithOneWildcard txtBattery_V;
    touchgfx::Image imgOilPres;
    touchgfx::BoxWithBorder boxPFuel;
    touchgfx::TextAreaWithOneWildcard txtPFuel;
    touchgfx::Image imgOilTemp;
    touchgfx::Image imgWaterTemp;
    touchgfx::Image imgTOrin;
    touchgfx::BoxWithBorder boxTOrin;
    touchgfx::TextAreaWithOneWildcard txtTOrin;
    touchgfx::Image imgBatteryV;
    touchgfx::Image img24v;
    touchgfx::BoxWithBorder box24v;
    touchgfx::TextAreaWithOneWildcard txt24v;
    touchgfx::Button btnNextPage;
    touchgfx::TextAreaWithOneWildcard dbgTextArea;
    touchgfx::TextArea textArea1;
    touchgfx::TextArea textArea1_1;
    touchgfx::TextArea textArea2;
    touchgfx::Button toDriver1;
    touchgfx::Button toDriver2;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TXTGEAR_SIZE = 2;
    touchgfx::Unicode::UnicodeChar txtGearBuffer[TXTGEAR_SIZE];
    static const uint16_t TXTSPEED_SIZE = 4;
    touchgfx::Unicode::UnicodeChar txtSpeedBuffer[TXTSPEED_SIZE];
    static const uint16_t TXTRPM_SIZE = 7;
    touchgfx::Unicode::UnicodeChar txtRpmBuffer[TXTRPM_SIZE];
    static const uint16_t TXTLAP_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtLapBuffer[TXTLAP_SIZE];
    static const uint16_t TXTTWATER_SIZE = 4;
    touchgfx::Unicode::UnicodeChar txtTWaterBuffer[TXTTWATER_SIZE];
    static const uint16_t TXTTOIL_SIZE = 4;
    touchgfx::Unicode::UnicodeChar txtTOilBuffer[TXTTOIL_SIZE];
    static const uint16_t TXTPOIL_SIZE = 6;
    touchgfx::Unicode::UnicodeChar txtPOilBuffer[TXTPOIL_SIZE];
    static const uint16_t TXTDS_SIZE = 40;
    touchgfx::Unicode::UnicodeChar txtDSBuffer[TXTDS_SIZE];
    static const uint16_t TXTAMI_SIZE = 40;
    touchgfx::Unicode::UnicodeChar txtAMIBuffer[TXTAMI_SIZE];
    static const uint16_t TXTEBS_SIZE = 10;
    touchgfx::Unicode::UnicodeChar txtEBSBuffer[TXTEBS_SIZE];
    static const uint16_t TXTBATTERY_V_SIZE = 6;
    touchgfx::Unicode::UnicodeChar txtBattery_VBuffer[TXTBATTERY_V_SIZE];
    static const uint16_t TXTPFUEL_SIZE = 6;
    touchgfx::Unicode::UnicodeChar txtPFuelBuffer[TXTPFUEL_SIZE];
    static const uint16_t TXTTORIN_SIZE = 4;
    touchgfx::Unicode::UnicodeChar txtTOrinBuffer[TXTTORIN_SIZE];
    static const uint16_t TXT24V_SIZE = 6;
    touchgfx::Unicode::UnicodeChar txt24vBuffer[TXT24V_SIZE];
    static const uint16_t DBGTEXTAREA_SIZE = 64;
    touchgfx::Unicode::UnicodeChar dbgTextAreaBuffer[DBGTEXTAREA_SIZE];

private:

    /*
     * Canvas Buffer Size
     */
    static const uint32_t CANVAS_BUFFER_SIZE = 12000;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];

    /*
     * Callback Declarations
     */
    touchgfx::Callback<MainInfotaimentViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // MAININFOTAIMENTVIEWBASE_HPP
