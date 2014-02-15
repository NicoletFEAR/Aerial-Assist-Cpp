#pragma once

#include "WPILib.h"
#include "SingleActionCommandBase.h"

class FireLauncher : public CommandBase
{
public:
	FireLauncher();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
