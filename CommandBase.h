#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"
#include "Subsystems/Chassis.h"
#include "Subsystems/GrabberArms.h"
#include "Subsystems/GrabberWheels.h"
#include "OI.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command {
public:
	CommandBase(const char *name);
	CommandBase();
	static void init();
	static Chassis* chassis;
	static GrabberWheels* grabberWheels;
	static GrabberArms* grabberArms;
	static OI *oi;
};

#endif
