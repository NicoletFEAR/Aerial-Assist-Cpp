#pragma once
#include "WPILib.h"
#include "../CommandBase.h"

class OverrideSensors : public CommandBase
{
public:
	OverrideSensors();
	void Initialize();
	void Execute();
	void End();
	void Interrupted();
	bool IsFinished();
};
