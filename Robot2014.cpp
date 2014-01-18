#include "WPILib.h"
#include "Commands/ActivateSolenoidCommand.h"

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
	
	virtual void TestInit()
	{
		Command* command = new ActivateSolenoid(1);
		command->Start();
	}
};

START_ROBOT_CLASS(Robot2014);

