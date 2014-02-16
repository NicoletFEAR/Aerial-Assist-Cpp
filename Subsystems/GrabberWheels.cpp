#include "GrabberWheels.h"
#include "../Robotmap.h"
#include "../Direction.h"
#include "WPILib.h"

GrabberWheels::GrabberWheels()
	: Subsystem("GrabberWheels"),
	  controller(new Victor(kGrabberWheelsMotor))
{

}

void GrabberWheels::InitDefaultCommand()
{
	
}

void GrabberWheels::MoveWheels(Direction direction)
{
	switch(direction)
	{
	case Forward:
		controller->Set(1);
		break;
	case Backward:
		controller->Set(-1);
		break;
	}
}

void GrabberWheels::StopWheels()
{
	controller->Set(0);
}
