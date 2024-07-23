#ifndef LOGGINGVIEW_HPP
#define LOGGINGVIEW_HPP

#include <gui_generated/logging_screen/LoggingViewBase.hpp>
#include <gui/logging_screen/LoggingPresenter.hpp>

class LoggingView : public LoggingViewBase
{
public:
    LoggingView();
    virtual ~LoggingView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LOGGINGVIEW_HPP
