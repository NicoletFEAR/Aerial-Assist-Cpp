#pragma once
#include "WPILib.h"
#include "../CommandBase.h"

class RunCompressor : public CommandBase
{
public:
	RunCompressor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
