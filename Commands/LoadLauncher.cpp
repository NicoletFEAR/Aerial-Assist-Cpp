#include "LoadLauncher.h"
#include "../Robotmap.h"
#include "../Potentiometers.h"

const double kMaxTurnDegrees = 360 * 9.75;

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
	return LauncherPotentiometer().Get() == kMaxTurnDegrees || limitSwitch.Get() == 1;
}

void LoadLauncher::End()
{
	launcher->StopMotor();
}

void LoadLauncher::Interrupted()
{
	End();
}
