#include "LoadLauncher.h"
#include "../Robotmap.h"
#include "../InternalButtons.h"

LoadLauncher::LoadLauncher()
	:CommandBase("LoadLauncher"),
	 limitSwitch(kLauncherLimitSwitch)
{
	Requires(launcher);
}

void LoadLauncher::Initialize()
{
}

void LoadLauncher::Execute()
{
	launcher->RunMotor(1.0f);
	SmartDashboard::PutString("Loading?", "LOADING");
}

bool LoadLauncher::IsFinished()
{
	if(SensorOverride().Get()) return false;
	return limitSwitch.Get() == 1;
}

void LoadLauncher::End()
{
	launcher->StopMotor();
	SmartDashboard::PutString("Loading?","");
}

void LoadLauncher::Interrupted()
{
	End();
}
