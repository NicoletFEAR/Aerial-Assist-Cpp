#ifndef SPEED_CONTROLLER_TEST_H
#define SPEED_CONTROLLER_TEST_H
#include "WPILib.h"
#include <memory>

namespace Subsystems
{
	class SpeedControllerTest: public Subsystem {
	private:
		std::auto_ptr<SpeedController> controller1;
		std::auto_ptr<SpeedController> controller2;
		std::auto_ptr<SpeedController> controller3;
		std::auto_ptr<SpeedController> controller4;
	public:
		SpeedControllerTest();
		void InitDefaultCommand();
		void SetSpeedController(int controllerID, float value);
	};
	
	extern SpeedControllerTest speedControllerTest;
}

#endif
