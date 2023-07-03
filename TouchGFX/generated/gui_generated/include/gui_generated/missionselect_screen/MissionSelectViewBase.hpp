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
#include <touchgfx/containers/scrollers/ScrollList.hpp>
#include <gui/containers/missionBtnContainer.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>

class MissionSelectViewBase : public touchgfx::View<MissionSelectPresenter>
{
public:
    MissionSelectViewBase();
    virtual ~MissionSelectViewBase();
    virtual void setupScreen();

    virtual void missionScrollListUpdateItem(missionBtnContainer& item, int16_t itemIndex)
    {
        // Override and implement this function in MissionSelect
    }

    /*
     * Virtual Action Handlers
     */
    virtual void requestResOpMode()
    {
        // Override and implement this function in MissionSelect
    }
    virtual void onChassisResetClicked()
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
    touchgfx::Button btnPrevPage;
    touchgfx::TextArea labelSelectMission;
    touchgfx::ScrollList missionScrollList;
    touchgfx::DrawableListItems<missionBtnContainer, 10> missionScrollListListItems;
    touchgfx::ButtonWithLabel btnResOpMode;
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  chassisResetBtn;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<MissionSelectViewBase, touchgfx::DrawableListItemsInterface*, int16_t, int16_t> updateItemCallback;
    touchgfx::Callback<MissionSelectViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<MissionSelectViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex);
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // MISSIONSELECTVIEWBASE_HPP
