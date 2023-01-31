#include <gui/maininfotaiment_screen/MainInfotaimentView.hpp>
#include <gui/maininfotaiment_screen/MainInfotaimentPresenter.hpp>

MainInfotaimentPresenter::MainInfotaimentPresenter(MainInfotaimentView& v)
    : view(v)
{

}

void MainInfotaimentPresenter::TESTFUNCTION()
{
	view.setRES(3);
}

void MainInfotaimentPresenter::activate()
{
	view.setGear(0);
	view.setRpm(0);
	view.setSpeed(0);
}

void MainInfotaimentPresenter::deactivate()
{
	
}

void MainInfotaimentPresenter::gearChanged()
{
	view.setGear(model->getGear());
}

void MainInfotaimentPresenter::infoChanged()
{
	view.setGear(model->getGear());
	view.setSpeed(model->getSpeed());
	view.setRpm(model->getRpm());

	view.setT_Water(model->getT_water());
	view.setT_Oil(model->getT_oil());
	view.setP_Oil(model->getP_oil());

	view.setThrottle_Perc(model->getThrottle_perc());
	view.setBrake_Perc(model->getBrake_perc());

	view.setRES(model->getRES());
	view.setLC(model->getLC());
	view.setCLT(model->getCLT());

	view.setBattery_V(model->getBattery_v());

	/* TODO: String variables */
}
