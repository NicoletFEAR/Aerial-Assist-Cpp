#include "GrabberArms.h"
#include "../Robotmap.h"
#include "../Direction.h" 
#include "WPILib.h"

GrabberArms::GrabberArms()
	: Subsystem("GrabberArms"),
	  controller(new Victor(kGrabberArmsMotor))
{

}

void GrabberArms::InitDefaultCommand()
{
	
}

void GrabberArms::MoveArms(Direction direction)
{
	switch(direction)
	{
	case Forward:
		controller->Set(.1);
		break;
	case Backward:
		controller->Set(-.1);
		break;
	}
}

void GrabberArms::StopArms()
{
	controller->Set(0);
}
