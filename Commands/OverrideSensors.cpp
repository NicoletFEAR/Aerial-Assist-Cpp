#include "OverrideSensors.h"
#include "../InternalButtons.h"

OverrideSensors::OverrideSensors()
	:SingleActionCommandBase("OverrideSensors")
{
}

void OverrideSensors::Initialize()
{
}

void OverrideSensors::DoAction()
{
	SensorOverride().SetPressed(true);
}
