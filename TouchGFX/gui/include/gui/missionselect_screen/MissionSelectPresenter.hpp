#ifndef MISSIONSELECTPRESENTER_HPP
#define MISSIONSELECTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>
#include "gui_shared_defs.h"

using namespace touchgfx;

class MissionSelectView;

class MissionSelectPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MissionSelectPresenter(MissionSelectView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    void requestMission(MmrMission type);

    void requestResOperationalMode();

    virtual ~MissionSelectPresenter() {};

private:
    MissionSelectPresenter();

    MissionSelectView& view;
};



#endif // MISSIONSELECTPRESENTER_HPP
