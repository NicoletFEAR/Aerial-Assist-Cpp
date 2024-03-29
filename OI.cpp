#include "OI.h"
#include "XBoxControllerMapping.h"
#include "Commands/FireLauncher.h"
#include "Commands/ReloadLauncher.h"
#include "Commands/MoveGrabberArms.h"
#include "Commands/MoveGrabberWheels.h"
#include "Commands/RunCompressor.h"
#include "Commands/OverrideSensors.h"

OI::OI()
	:driveController(new Joystick(1)),
	 gameMechController(new Joystick(2))
{
	InitializeButton(new JoystickButton(gameMechController, kAButton), new FireLauncher(), &Button::ToggleWhenPressed);
	InitializeButton(new JoystickButton(gameMechController, kXButton), new ReloadLauncher(), &Button::ToggleWhenPressed);
	InitializeButton(new JoystickButton(gameMechController, kBButton), new MoveGrabberWheels(Forward), &Button::ToggleWhenPressed);
	InitializeButton(new JoystickButton(gameMechController, kYButton), new MoveGrabberWheels(Backward), &Button::ToggleWhenPressed);
	InitializeButton(new JoystickButton(gameMechController, kLeftBumper), new MoveGrabberArms(Backward), &Button::ToggleWhenPressed);
	InitializeButton(new JoystickButton(gameMechController, kRightBumper), new MoveGrabberArms(Forward), &Button::ToggleWhenPressed);
	InitializeButton(new JoystickButton(gameMechController, kBackButton), new OverrideSensors(), &Button::ToggleWhenPressed);
	SmartDashboard::PutNumber("ArmDownSpeed", .1);
	SmartDashboard::PutNumber("ArmUpSpeed", -.1);
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

