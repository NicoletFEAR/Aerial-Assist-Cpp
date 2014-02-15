#include "OI.h"

OI::OI()
	:driveController(new Joystick(1))
{
	// Process operator interface input here.
}

GenericHID* OI::DriveController()
{
	return driveController;
}
