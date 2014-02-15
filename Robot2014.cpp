#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/MoveGrabberArms.h"
#include "Commands/MoveGrabberWheels.h"
#include <iostream>

class Robot2014 : public IterativeRobot {
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	
	virtual void RobotInit() {
		CommandBase::init();
		autonomousCommand = new ExampleCommand();
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
		SmartDashboard::PutData("Grabber Arm Down", new MoveGrabberArms(Forward));
		SmartDashboard::PutData("Grabber Arm Up", new MoveGrabberArms(Backward));
		SmartDashboard::PutData("Wheels Forward", new MoveGrabberWheels(Forward));
		SmartDashboard::PutData("Wheels Backward", new MoveGrabberWheels(Backward));
		SmartDashboard::PutNumber("Arm Speed Down", 1);
		SmartDashboard::PutNumber("Arm Speed Up", 1);
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

