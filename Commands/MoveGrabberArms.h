#pragma once

#include "WPILib.h"
#include "../CommandBase.h"
#include "../Direction.h"

class MoveGrabberArms : public CommandBase
{
private:
	Direction direction;
	DigitalInput armUpLimitSwitch;
	DigitalInput armDownLimitSwitch;
public:
	MoveGrabberArms(Direction direction);
	void Initialize();
	void Execute();
	void End();
	void Interrupted();
	bool IsFinished();
};
