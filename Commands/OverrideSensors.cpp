#include "OverrideSensors.h"
#include "../InternalButtons.h"

OverrideSensors::OverrideSensors()
	:CommandBase("OverrideSensors")
{
}

void OverrideSensors::Initialize()
{
}

void OverrideSensors::Execute()
{
	SensorOverride().SetPressed(true);
	SmartDashboard::PutString("Override?", "OVERRIDE ENABLED");
}

void OverrideSensors::Interrupted()
{
	End();
}

void OverrideSensors::End()
{
	SensorOverride().SetPressed(false);
	SmartDashboard::PutString("Override?", "");
}

bool OverrideSensors::IsFinished()
{
	return false;
}
