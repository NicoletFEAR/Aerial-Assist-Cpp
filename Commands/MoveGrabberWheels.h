#pragma once
#include "../CommandBase.h"


class MoveGrabberWheels : CommandBase
{
private:
	Direction direction;
public:
	MoveGrabberWheels(Direction direction);
	void Initialize();
	void Execute();
	void End();
	void Interrupted();
	bool IsFinished();
};
