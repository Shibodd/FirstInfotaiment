/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef LOGGINGVIEWBASE_HPP
#define LOGGINGVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/logging_screen/LoggingPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/containers/ScrollableContainer.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/RadioButton.hpp>

class LoggingViewBase : public touchgfx::View<LoggingPresenter>
{
public:
    LoggingViewBase();
    virtual ~LoggingViewBase();
    virtual void setupScreen();

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
    touchgfx::ScrollableContainer scrollableContainer1;
    touchgfx::TextArea textArea1;
    touchgfx::Container levelSelectorsContainer;
    touchgfx::Container filterContainerDebug;
    touchgfx::RadioButton filterCheckbox;
    touchgfx::TextArea filterName;
    touchgfx::Container filterContainerInfo;
    touchgfx::RadioButton filterCheckbox_1;
    touchgfx::TextArea filterName_1;
    touchgfx::Container filterContainerWarning;
    touchgfx::RadioButton filterCheckbox_1_1;
    touchgfx::TextArea filterName_1_1;
    touchgfx::Container filterContainerError;
    touchgfx::RadioButton filterCheckbox_1_2;
    touchgfx::TextArea filterName_1_2;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<LoggingViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // LOGGINGVIEWBASE_HPP
