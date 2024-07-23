#include <gui/logging_screen/LoggingView.hpp>
#include <gui/containers/missionBtnContainer.hpp>

LoggingView::LoggingView()
{

}

void LoggingView::setupScreen()
{
    LoggingViewBase::setupScreen();
}

void LoggingView::tearDownScreen()
{
    LoggingViewBase::tearDownScreen();
}


void LoggingView::addLogMessage(std::string msg) {
	auto btn = missionBtnContainer();
	btn.setText("Test");
	this->logsContainer.add(btn);
}
