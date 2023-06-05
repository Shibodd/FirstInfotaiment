#ifndef MISSIONSELECTVIEW_HPP
#define MISSIONSELECTVIEW_HPP

#include <gui_generated/missionselect_screen/MissionSelectViewBase.hpp>
#include <gui/containers/missionBtnContainer.hpp>
#include <gui/missionselect_screen/MissionSelectPresenter.hpp>
#include <touchgfx/Callback.hpp>

class MissionSelectView : public MissionSelectViewBase
{
public:
    MissionSelectView();
    
    virtual ~MissionSelectView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void missionScrollListUpdateItem(missionBtnContainer& item, int16_t itemIndex);
    
    virtual void requestResOpMode();
    virtual void onChassisResetClicked();
protected:

    Callback<MissionSelectView, int16_t> scrollListItemSelectedCallback;
    void scrollListItemSelectedHandler(int16_t itemSelected);
};

#endif // MISSIONSELECTVIEW_HPP
