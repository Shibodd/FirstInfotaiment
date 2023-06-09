/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef STARTUPVIEWBASE_HPP
#define STARTUPVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/startup_screen/StartupPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class StartupViewBase : public touchgfx::View<StartupPresenter>
{
public:
    StartupViewBase();
    virtual ~StartupViewBase();
    virtual void setupScreen();
    virtual void afterTransition();
    virtual void handleTickEvent();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Image backgroundStartup;
    touchgfx::TextArea textArea1;

private:

    /*
     * Delay Variable Declarations
     */
    static const uint16_t FROMSTARTUPTOINFOTAIMENT_DURATION = 144;
    uint16_t fromStartupToInfotaimentCounter;

};

#endif // STARTUPVIEWBASE_HPP
