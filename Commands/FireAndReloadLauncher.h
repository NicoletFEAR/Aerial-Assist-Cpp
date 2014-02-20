#pragma once
#include "WPILib.h"
#include "FireLauncher.h"
#include "ReloadLauncher.h"

class FireAndReloadLauncher : public CommandGroup
{
public:
	FireAndReloadLauncher()
		:CommandGroup("FireAndReloadLauncher")
	{
		AddSequential(new FireLauncher());
		AddSequential(new ReloadLauncher());
	}
};
