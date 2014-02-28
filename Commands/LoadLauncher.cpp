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
	launcher->RunMotor(0.5f);
}

bool LoadLauncher::IsFinished()
{
	if(SensorOverride().Get()) return false;
	return limitSwitch.Get() == 1;
}

void LoadLauncher::End()
{
	launcher->StopMotor();
}

void LoadLauncher::Interrupted()
{
	End();
}
