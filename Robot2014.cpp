#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"

class Robot2014 : public IterativeRobot
{
	private:
	
	virtual void RobotInit()
	{
	}
	
	virtual void AutonomousInit()
	{
		
	}
	
	virtual void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit()
	{
		
	}
	
	virtual void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot2014);

