#include "EngageClutch.h"
#include "../Potentiometers.h"

EngageClutch::EngageClutch()
	:CommandBase("EngageClutch")
{
	Requires(launcher);
	SetTimeout(.5);
}

void EngageClutch::Initialize()
{
	originalPotReading = LauncherPotentiometer().Get();
}


void EngageClutch::Execute()
{
	launcher->RunMotor(.5);
	launcher->EngageClutch();
}

void EngageClutch::End()
{
	launcher->StopMotor();
}

void EngageClutch::Interrupted()
{
	End();
}

bool EngageClutch::IsFinished()
{
	return originalPotReading != LauncherPotentiometer().Get() || IsTimedOut();
}
