#pragma once
#include "WPILib.h"
#include "SingleActionCommandBase.h"

class OverrideSensors : public SingleActionCommandBase
{
public:
	OverrideSensors();
	void Initialize();
protected:
	void DoAction();
};
