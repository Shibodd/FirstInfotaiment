/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef LOGLINECONTAINERBASE_HPP
#define LOGLINECONTAINERBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class logLineContainerBase : public touchgfx::Container
{
public:
    logLineContainerBase();
    virtual ~logLineContainerBase();
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::TextArea separtorLabel;
    touchgfx::TextAreaWithOneWildcard levelLabel;
    touchgfx::TextAreaWithOneWildcard messageLabel;

private:

};

#endif // LOGLINECONTAINERBASE_HPP