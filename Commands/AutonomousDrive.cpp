#include "AutonomousDrive.h"

AutonomousDrive::AutonomousDrive()
	:CommandBase("AutonomousDrive")
{
	Requires(chassis);
	SetTimeout(0.5);
}

void AutonomousDrive::Initialize()
{
	
}

void AutonomousDrive::Execute()
{
	chassis->Drive(0, -1, 0); //Negative because RobotDrive inverts our inputs
}

void AutonomousDrive::End()
{
	chassis->Drive(0, 0, 0);  //Turn off motors
}

void AutonomousDrive::Interrupted()
{
	End();
}

bool AutonomousDrive::IsFinished()
{
	return IsTimedOut();
}
