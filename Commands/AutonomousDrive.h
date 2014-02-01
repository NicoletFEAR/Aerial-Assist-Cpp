#pragma once
#include "../CommandBase.h"

class AutonomousDrive : public CommandBase
{
public:
	AutonomousDrive();
	void Initialize();
	void Execute();
	void End();
	void Interrupted();
	bool IsFinished();
};
