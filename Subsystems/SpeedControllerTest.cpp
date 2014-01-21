#include "SpeedControllerTest.h"
#include <iostream>

Subsystems::SpeedControllerTest::SpeedControllerTest() :
	Subsystem("SpeedControllerTest"),
	controller1(new Jaguar(1)),
	controller2(new Jaguar(2)),
	controller3(new Jaguar(3)),
	controller4(new Jaguar(4))
{
	
}
    
void Subsystems::SpeedControllerTest::InitDefaultCommand()
{
	
}

void Subsystems::SpeedControllerTest::SetSpeedController(int controllerID, float value)
{
	switch(controllerID)
	{
	case 1:
		controller1->Set(value);
		break;
	case 2:
		controller2->Set(value);
		break;
	case 3:
		controller3->Set(value);
		break;
	case 4:
		controller4->Set(value);
		break;
	default:
		std::cerr<<"Invalid Controller ID\n";
		break;
	}
}

Subsystems::SpeedControllerTest Subsystems::speedControllerTest;

