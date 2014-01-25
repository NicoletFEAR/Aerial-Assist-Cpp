#pragma once
#include "CommandBase.h"

class SingleActionCommandBase : public CommandBase
{
private:
	bool isFinished;
public:
	SingleActionCommandBase(const char* name);
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
protected:
	virtual void DoAction() = 0;
};
