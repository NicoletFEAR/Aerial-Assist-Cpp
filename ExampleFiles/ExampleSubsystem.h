#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

namespace Subsystems
{
	class ExampleSubsystem: public Subsystem {
	public:
		ExampleSubsystem();
		void InitDefaultCommand();
	};
	
	extern ExampleSubsystem exampleSubsystem;
}

#endif
