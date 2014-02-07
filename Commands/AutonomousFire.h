#pragma once
#include "WPILib.h"
#include "LoadLauncher.h"
#include "FireLauncher.h"

class AutonomousFire : public CommandGroup
{
public:
	AutonomousFire()
		:CommandGroup("AutonomousFire")
	{
		AddSequential(new LoadLauncher());
		AddSequential(new FireLauncher());
	}
};
