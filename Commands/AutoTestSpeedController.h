#ifndef AUTO_TEST_SPEED_CONTROLLER_H
#define AUTO_TEST_SPEED_CONTROLLER_H
#include "WPILib.h"

namespace Commands
{
	class AutoTestSpeedController : public Command
	{
		int controllerID;
	public:
		AutoTestSpeedController(int controllerID);
	protected:
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
	};
}

#endif
