#include "ActivateSolenoidCommand.h"

ActivateSolenoid::ActivateSolenoid(uint32_t channel)
	:solenoid(channel)
{
	
}

// Called just before this Command runs the first time
void ActivateSolenoid::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ActivateSolenoid::Execute()
{
	solenoid.Set(true);
}

// Make this return true when this Command no longer needs to run execute()
bool ActivateSolenoid::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ActivateSolenoid::End()
{
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ActivateSolenoid::Interrupted() {
}
