#pragma once
#include "WPILib.h"
#include "EngageClutch.h"
#include "LoadLauncher.h"

class ReloadLauncher : public CommandGroup
{
public:
	ReloadLauncher()
		:CommandGroup("ReloadLauncher")
	{
		AddSequential(new EngageClutch());
		AddSequential(new LoadLauncher());
	}
};
