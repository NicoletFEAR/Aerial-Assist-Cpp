#include "MoveGrabberArms.h"

MoveGrabberArms::MoveGrabberArms(Direction direction)
	:CommandBase("MoveGrabberArms"),
	direction(direction),
	 armDownLimitSwitch(1),
	 armUpLimitSwitch(2)
{
	Requires(grabberArms);
}

// Called just before this Command runs the first time
void MoveGrabberArms::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void MoveGrabberArms::Execute() {
	grabberArms->MoveWheels(direction);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveGrabberArms::IsFinished() {
	switch(direction)
	{
	case Forward:
		return armDownLimitSwitch.Get() == 1;
	case Backward:
		return armUpLimitSwitch.Get() == 0;
	default:
		return true;
	}
}

// Called once after isFinished returns true
void MoveGrabberArms::End() {
	grabberArms->StopWheels();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveGrabberArms::Interrupted() {
	End();
}
