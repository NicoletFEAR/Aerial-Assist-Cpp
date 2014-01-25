#pragma once

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class TeleOpDrive: public CommandBase
{
private:
	GenericHID* controller;
	float GetConvertedDriveAxis(int axis);
	float GetConvertedTurnAxis(int axis);
public:
	TeleOpDrive();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

