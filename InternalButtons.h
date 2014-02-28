#pragma once
#include "WPILib.h"

inline InternalButton& SensorOverride()
{
	static InternalButton sensorOverride;
	return sensorOverride;
}
