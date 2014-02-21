#include "OI.h"
#include "XBoxControllerMapping.h"
#include "Commands/FireAndReloadLauncher.h"
#include "Commands/MoveGrabberArms.h"
#include "Commands/MoveGrabberWheels.h"
#include "Commands/RunCompressor.h"

OI::OI()
	:driveController(new Joystick(1)),
	 gameMechController(new Joystick(2))
{
	InitializeButton(new JoystickButton(gameMechController, kAButton), new FireAndReloadLauncher(), &Button::WhenPressed);
	InitializeButton(new JoystickButton(gameMechController, kYButton), new MoveGrabberWheels(Forward), &Button::ToggleWhenPressed);
	InitializeButton(new JoystickButton(gameMechController, kBButton), new MoveGrabberWheels(Backward), &Button::ToggleWhenPressed);
	InitializeButton(new JoystickButton(gameMechController, kRightBumper), new MoveGrabberArms(Backward), &Button::WhenPressed);
	InitializeButton(new JoystickButton(gameMechController, kLeftBumper), new MoveGrabberArms(Forward), &Button::WhenPressed);
	SmartDashboard::PutData(new RunCompressor());
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

