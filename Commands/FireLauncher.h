#pragma once

#include "WPILib.h"
#include "SingleActionCommandBase.h"

class FireLauncher : public CommandBase
{
private:
	double lastPotReading;
public:
	FireLauncher();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
