#include "WPILib.h"
#include "AutonomousDrive.h"
#include "AutonomousFire.h"

class Autonomous : public CommandGroup
{
public:
	Autonomous()
		:CommandGroup("Autonomous")
	{
		AddSequential(new AutonomousDrive());
		AddSequential(new AutonomousFire());
	}
};
