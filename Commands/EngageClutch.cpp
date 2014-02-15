#include "EngageClutch.h"

EngageClutch::EngageClutch()
	:CommandBase("EngageClutch")
{
	Requires(launcher);
	SetTimeout(.5);
}

void EngageClutch::Initialize()
{
	
}


void EngageClutch::Execute()
{
	launcher->RunMotor(.25);
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
	return IsTimedOut();
}
