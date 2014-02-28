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
#include "Robotmap.h"
class Robot2014 : public IterativeRobot {
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	
	virtual void RobotInit() {
		std::cout<<"Start RobotInit\n";
		std::cout<<"Init CommandBase (Subsystems and OI)\n";
		CommandBase::init();
		std::cout<<"Init AutonomousDrive\n";
		autonomousCommand = new AutonomousDrive();
		std::cout<<"Init LiveWindow reference\n";
		lw = LiveWindow::GetInstance();
		Compressor * c = new Compressor(kPressureSwitchChannel, kCompressorRelayChannel);
		c->Start();
		std::cout<<"End of RobotInit"<<std::endl;
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

