#include "TeleOpDrive.h"

TeleOpDrive::TeleOpDrive()
	:CommandBase("TeleOpDrive")
{
	Requires(chassis);
}

// Called just before this Command runs the first time
void TeleOpDrive::Initialize()
{
	
}

// Called repeatedly when this Command is scheduled to run
void TeleOpDrive::Execute()
{
	
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
