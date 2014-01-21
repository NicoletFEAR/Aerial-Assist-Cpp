#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
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
