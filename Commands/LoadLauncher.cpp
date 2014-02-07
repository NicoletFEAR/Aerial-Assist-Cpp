#include "LoadLauncher.h"
#include "../Robotmap.h"

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
}

bool LoadLauncher::IsFinished()
{
	return limitSwitch.Get();
}

void LoadLauncher::End()
{
	launcher->StopMotor();
}

void LoadLauncher::Interrupted()
{
	End();
}
