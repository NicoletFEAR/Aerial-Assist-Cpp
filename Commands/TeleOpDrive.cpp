#include "TeleOpDrive.h"
#include "../Robotmap.h"
#include "../XBoxControllerMapping.h"
#include <cmath>

TeleOpDrive::TeleOpDrive()
	:CommandBase("TeleOpDrive")
{
	Requires(chassis);
}

// Called just before this Command runs the first time
void TeleOpDrive::Initialize()
{	
}

float TeleOpDrive::GetConvertedDriveAxis(int axis)
{
	float axisValue = oi->DriveController()->GetRawAxis(axis);
	axisValue = std::abs(axisValue) >= .04f ? axisValue : 0;//Deadzone
	int sign = axisValue >= 0 ? 1 : -1; //Store sign of axis to reapply after squaring
	float squaredAxis = axisValue * axisValue;
	return sign * squaredAxis;
}

float TeleOpDrive::GetConvertedTurnAxis(int axis)
{
	return oi->DriveController()->GetRawAxis(axis) * (1.0f / 3.0f);
}

// Called repeatedly when this Command is scheduled to run
void TeleOpDrive::Execute()
{
	float x = GetConvertedDriveAxis(kLeftControlStickXAxis);
	float y = GetConvertedDriveAxis(kLeftControlStickYAxis);
	float turn = GetConvertedTurnAxis(kRightControlStickXAxis);
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
