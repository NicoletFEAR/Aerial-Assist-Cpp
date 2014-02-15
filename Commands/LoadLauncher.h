#pragma once

#include "../CommandBase.h"

class LoadLauncher : public CommandBase
{
private:
	DigitalInput limitSwitch;
public:
	LoadLauncher();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
