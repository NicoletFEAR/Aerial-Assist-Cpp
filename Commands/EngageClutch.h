#pragma once
#include "WPILib.h"
#include "../CommandBase.h"

class EngageClutch : public CommandBase
{
public:
	EngageClutch();
	void Initialize();
	void Execute();
	void End();
	void Interrupted();
	bool IsFinished();
};
