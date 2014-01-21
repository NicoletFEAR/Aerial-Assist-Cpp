#include "AutoTestSpeedController.h"
#include "../Subsystems/SpeedControllerTest.h"
#include <iostream>

Commands::AutoTestSpeedController::AutoTestSpeedController(int controllerID):
	Command("AutoTestSpeedController"),
	controllerID(controllerID)
{
	Requires(&Subsystems::speedControllerTest);
}

void Commands::AutoTestSpeedController::Initialize()
{
	
}

void Commands::AutoTestSpeedController::Execute()
{
	std::clog<<"Command Started\n";
	std::clog<<"Start Motor "<<controllerID<<"\n";
	Subsystems::speedControllerTest.SetSpeedController(controllerID, .5);
}

bool Commands::AutoTestSpeedController::IsFinished()
{
	return false;
}

void Commands::AutoTestSpeedController::End()
{
	std::clog<<"Stop Motor "<<controllerID<<"\n";
	Subsystems::speedControllerTest.SetSpeedController(controllerID, 0);
}

void Commands::AutoTestSpeedController::Interrupted()
{
	
}
