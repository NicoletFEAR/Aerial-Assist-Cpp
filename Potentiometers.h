#include "AnalogPotentiometer.h"
#include "Robotmap.h"

const double kPotScale = 3600 / 5; // (degrees / volts)

inline AnalogPotentiometer& GrabberPotentiometer()
{
	static AnalogPotentiometer grabberPot(kGrabberPotChannel, kPotScale, 0);
	return grabberPot;
}

inline AnalogPotentiometer& LauncherPotentiometer()
{
	static AnalogPotentiometer launcherPot(kLauncherPotChannel, kPotScale, 0);
	return launcherPot;
}
