#pragma once
#include "WPILib.h"
#include "../CommandBase.h"

class EngageClutch : public CommandBase
{
private:
	double originalPotReading;
public:
	EngageClutch();
	void Initialize();
	void Execute();
	void End();
	void Interrupted();
	bool IsFinished();
};
