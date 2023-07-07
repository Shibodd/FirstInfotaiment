/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MISSIONSELECTVIEWBASE_HPP
#define MISSIONSELECTVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/missionselect_screen/MissionSelectPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>

class MissionSelectViewBase : public touchgfx::View<MissionSelectPresenter>
{
public:
    MissionSelectViewBase();
    virtual ~MissionSelectViewBase();
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void onChassisResetClicked()
    {
        // Override and implement this function in MissionSelect
    }
    virtual void onIdleBtnClicked()
    {
        // Override and implement this function in MissionSelect
    }
    virtual void onAccelerationBtnClicked()
    {
        // Override and implement this function in MissionSelect
    }
    virtual void onSkidpadBtnClicked()
    {
        // Override and implement this function in MissionSelect
    }
    virtual void onAutocrossBtnClicked()
    {
        // Override and implement this function in MissionSelect
    }
    virtual void onTrackdriveBtnClicked()
    {
        // Override and implement this function in MissionSelect
    }
    virtual void onEbsTestBtnClicked()
    {
        // Override and implement this function in MissionSelect
    }
    virtual void onInspectionBtnClicked()
    {
        // Override and implement this function in MissionSelect
    }
    virtual void onManualBtnClicked()
    {
        // Override and implement this function in MissionSelect
    }
    virtual void onDebugBtnClicked()
    {
        // Override and implement this function in MissionSelect
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Button btnNextPage;
    touchgfx::Button btnPrevPage;
    touchgfx::TextArea labelSelectMission;
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  chassisResetBtn;
    touchgfx::ButtonWithLabel idleBtn;
    touchgfx::ButtonWithLabel trackdriveBtn;
    touchgfx::ButtonWithLabel ebsTestBtn;
    touchgfx::ButtonWithLabel inspectionBtn;
    touchgfx::ButtonWithLabel manualBtn;
    touchgfx::ButtonWithLabel debugBtn;
    touchgfx::ButtonWithLabel accelerationBtn;
    touchgfx::ButtonWithLabel skidpadBtn;
    touchgfx::ButtonWithLabel autocrossBtn;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<MissionSelectViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<MissionSelectViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // MISSIONSELECTVIEWBASE_HPP
