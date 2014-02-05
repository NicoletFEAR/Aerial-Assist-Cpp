#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
Chassis* CommandBase::chassis = NULL;
GrabberArms* CommandBase::grabberArms = NULL;
GrabberWheels* CommandBase::grabberWheels = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	chassis = new Chassis();
	grabberArms = new GrabberArms();
	grabberWheels = new GrabberWheels();
	oi = new OI();
}
