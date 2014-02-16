#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "Commands/Autonomous.h"
#include "CommandBase.h"
#include "Commands/MoveGrabberArms.h"
#include "Commands/MoveGrabberWheels.h"
#include <iostream>

#include "Commands/LoadLauncher.h"
#include "Commands/FireLauncher.h"
#include "Commands/EngageClutch.h"

class Robot2014 : public IterativeRobot {
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	
	virtual void RobotInit() {
		CommandBase::init();
		autonomousCommand = new Autonomous();
		lw = LiveWindow::GetInstance();
	}
	
	virtual void AutonomousInit() {
		autonomousCommand->Start();
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		autonomousCommand->Cancel();
		std::cout<<"Start Teleop\r\n";
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot2014);

