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
	static const double armUpAngle = 90;
	static const double armDownAngle = 35;
public:
	//Forward = Up, Backward = Down
	MoveGrabberArms(Direction direction);
	void Initialize();
	void Execute();
	void End();
	void Interrupted();
	bool IsFinished();
};
