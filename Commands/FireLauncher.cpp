#include "FireLauncher.h"

FireLauncher::FireLauncher()
	:CommandBase("FireLauncher")
{
	Requires(launcher);
	SetTimeout(5);
}

void FireLauncher::Initialize()
{
	
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
	return IsTimedOut();
}
