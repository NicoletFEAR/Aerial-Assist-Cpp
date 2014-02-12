#pragma once
#include "WPILib.h"
#include "../CommandBase.h"

class EngageClutch : public CommandBase
{
private:
	Encoder encoder;
public:
	EngageClutch();
	void Initialize();
	void Execute();
	void End();
	void Interrupted();
	bool IsFinished();
};
