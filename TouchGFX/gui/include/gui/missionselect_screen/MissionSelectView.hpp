#ifndef MISSIONSELECTVIEW_HPP
#define MISSIONSELECTVIEW_HPP

#include <gui_generated/missionselect_screen/MissionSelectViewBase.hpp>
#include <gui/missionselect_screen/MissionSelectPresenter.hpp>

class MissionSelectView : public MissionSelectViewBase
{
public:
    MissionSelectView();
    virtual ~MissionSelectView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MISSIONSELECTVIEW_HPP
