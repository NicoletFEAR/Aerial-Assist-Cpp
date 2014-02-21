#pragma once
#include "../CommandBase.h"


class MoveGrabberWheels : public CommandBase
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
