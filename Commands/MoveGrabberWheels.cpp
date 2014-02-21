#include "MoveGrabberWheels.h"

MoveGrabberWheels::MoveGrabberWheels(Direction direction)
	:CommandBase("MoveGrabberWheels"),
	 direction(direction){
	Requires(grabberWheels);
}

// Called just before this Command runs the first time
void MoveGrabberWheels::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void MoveGrabberWheels::Execute() {
	grabberWheels->MoveWheels(direction);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveGrabberWheels::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveGrabberWheels::End() {
	grabberWheels->StopWheels();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveGrabberWheels::Interrupted() {
	End();
}
