#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

namespace Subsystems
{
	class DriveTrain: public Subsystem {
	public:
		DriveTrain();
		void InitDefaultCommand();
	};
	
	extern DriveTrain driveTrain;
}

#endif
