#pragma once
#include "WPILib.h"
#include "GrabBall.h"
#include "LoadLauncher.h"

class GrabAndLoad : public CommandGroup
{
public:
	GrabAndLoad()
		:CommandGroup("GrabAndLoad")
	{
		AddParallel(new GrabBall());
		AddParallel(new LoadLauncher());
	}
};
