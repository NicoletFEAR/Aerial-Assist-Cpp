#pragma once
#include "WPILib.h"
#include "MoveGrabberArms.h"
#include "MoveGrabberWheels.h"

class GrabBall : public CommandGroup
{
public:
	GrabBall()
		:CommandGroup("GrabBall")
	{
		AddSequential(new MoveGrabberArms(Backward));
		AddSequential(new MoveGrabberWheels(Forward));
		AddSequential(new MoveGrabberArms(Forward));
	}
};
