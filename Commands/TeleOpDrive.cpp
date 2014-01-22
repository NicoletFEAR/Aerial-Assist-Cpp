#include "TeleOpDrive.h"
#include "../Robotmap.h"
#include "../XBoxControllerMapping.h"


TeleOpDrive::TeleOpDrive()
	:CommandBase("TeleOpDrive"),
	 controller(new Joystick(kDriveJoystickInput))
{
	Requires(chassis);
}

// Called just before this Command runs the first time
void TeleOpDrive::Initialize()
{	
}

float TeleOpDrive::GetConvertedAxis(int axis)
{
	return controller->GetRawAxis(axis);
}

// Called repeatedly when this Command is scheduled to run
void TeleOpDrive::Execute()
{
	float x = GetConvertedAxis(kLeftControlStickXAxis);
	float y = GetConvertedAxis(kLeftControlStickYAxis);
	float turn = GetConvertedAxis(kRightControlStickXAxis);
	chassis->Drive(x, y, turn);
}

// Make this return true when this Command no longer needs to run execute()
bool TeleOpDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void TeleOpDrive::End()
{
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleOpDrive::Interrupted()
{
}
