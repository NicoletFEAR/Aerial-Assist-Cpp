#include "OI.h"
#include "XBoxControllerMapping.h"
#include "Commands/FireAndReloadLauncher.h"

OI::OI()
	:driveController(new Joystick(1)),
	 gameMechController(new Joystick(2))
{
	InitializeButton(new JoystickButton(gameMechController, kAButton), new FireAndReloadLauncher(), &Button::WhenPressed);
}

GenericHID* OI::DriveController()
{
	return driveController;
}


void OI::InitializeButton(Button* button, Command* command, RegistrationMethod registrar)
{
	(button->*registrar)(command);
	buttons.push_back(button);
}

