#include "SingleActionCommandBase.h"

SingleActionCommandBase::SingleActionCommandBase(const char* name)
	:CommandBase(name),
	 isFinished(false)
{
	
}

void SingleActionCommandBase::Execute()
{
	DoAction();
	isFinished = true;
}

bool SingleActionCommandBase::IsFinished()
{
	return isFinished;
}

void SingleActionCommandBase::End()
{
	
}

void SingleActionCommandBase::Interrupted()
{
	
}
