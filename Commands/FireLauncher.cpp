#include "FireLauncher.h"
#include "../Potentiometers.h"

FireLauncher::FireLauncher()
	:CommandBase("FireLauncher")
{
	Requires(launcher);
	SetTimeout(.5);
}

void FireLauncher::Initialize()
{
	lastPotReading = LauncherPotentiometer().Get();
}

void FireLauncher::Execute()
{
	launcher->ReleaseClutch();
}

void FireLauncher::End()
{
	
}

void FireLauncher::Interrupted()
{
	End();
}

bool FireLauncher::IsFinished()
{
	double newReading = LauncherPotentiometer().Get();
	if(lastPotReading == newReading)
	{
		return true;
	}
	else
	{
		lastPotReading = newReading;
		return IsTimedOut();
	}
}
