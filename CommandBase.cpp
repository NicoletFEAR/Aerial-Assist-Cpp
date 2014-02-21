#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Commands/Scheduler.h"
#include <iostream>

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
Chassis* CommandBase::chassis = NULL;
Launcher* CommandBase::launcher = NULL;
GrabberArms* CommandBase::grabberArms = NULL;
GrabberWheels* CommandBase::grabberWheels = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	std::cout<<"Chassis\n";
	chassis = new Chassis();
	std::cout<<"Launcher\n";
	launcher = new Launcher();
	std::cout<<"Grabber Arms\n";
	grabberArms = new GrabberArms();
	std::cout<<"Grabber Wheels\n";
	grabberWheels = new GrabberWheels();
	std::cout<<"OI\n";
	oi = new OI();
	std::cout<<"Finished CommandBase::init"<<std::endl;
}
