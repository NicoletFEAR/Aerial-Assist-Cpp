#pragma once
#include "WPILib.h"
#include "AutonomousDrive.h"
#include "GrabAndLoad.h"

class Autonomous : public CommandGroup
{
public:
	Autonomous()
		:CommandGroup("Autonomous")
	{
		AddSequential(new GrabAndLoad());
		AddSequential(new AutonomousDrive());
	}
};
