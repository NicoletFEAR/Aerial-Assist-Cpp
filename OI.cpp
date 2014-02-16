#include "OI.h"
#include "XBoxControllerMapping.h"
#include "Commands/FireAndReloadLauncher.h"
#include "Commands/MoveGrabberArms.h"
#include "Commands/MoveGrabberWheels.h"

class AxisButton : public Button
{
private:
	GenericHID* controller;
	int axis;
	float threshold;
	bool checkForGreaterThan;
public:
	AxisButton(GenericHID* controller, int axis, float threshold, bool greaterThan)
		:axis(axis),
		 threshold(threshold),
		 checkForGreaterThan(greaterThan)
	{
	}
	
	bool Get()
	{
		if(checkForGreaterThan) return controller->GetRawAxis(axis) > threshold;
		else return controller->GetRawAxis(axis) < threshold;
	}
};


OI::OI()
	:driveController(new Joystick(1)),
	 gameMechController(new Joystick(2))
{
	InitializeButton(new JoystickButton(gameMechController, kAButton), new FireAndReloadLauncher(), &Button::WhenPressed);
	InitializeButton(new JoystickButton(gameMechController, kYButton), new MoveGrabberWheels(Forward), &Button::ToggleWhenPressed);
	InitializeButton(new JoystickButton(gameMechController, kBButton), new MoveGrabberWheels(Backward), &Button::ToggleWhenPressed);
	InitializeButton(new AxisButton(gameMechController, kDPadHorizontalAxis, 1, true), new MoveGrabberArms(Forward), &Button::WhenPressed);
	InitializeButton(new AxisButton(gameMechController, kDPadHorizontalAxis, -1, true), new MoveGrabberArms(Backward), &Button::WhenPressed);
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

