#include "MoveGrabberArms.h"
#include "../Robotmap.h"
#include "../InternalButtons.h"

MoveGrabberArms::MoveGrabberArms(Direction direction)
	:CommandBase("MoveGrabberArms"),
	direction(direction),
	 armUpLimitSwitch(kGrabberUpSwitch),
	armDownLimitSwitch(kGrabberDownSwitch)
{
	Requires(grabberArms);
	if(direction == Backward) //Dropping arm down
	{
		SetTimeout(.3);
	}
}

// Called just before this Command runs the first time
void MoveGrabberArms::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void MoveGrabberArms::Execute() {
	grabberArms->MoveArms(direction);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveGrabberArms::IsFinished() {
	if(SensorOverride().Get()) return false;
	switch(direction)
	{
	case Forward:
		return armUpLimitSwitch.Get();
	case Backward:
		return IsTimedOut() || armDownLimitSwitch.Get();
	default:
		return true;
	}
}

// Called once after isFinished returns true
void MoveGrabberArms::End() {
	grabberArms->StopArms();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveGrabberArms::Interrupted() {
	End();
}
