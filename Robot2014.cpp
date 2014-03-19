#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "Commands/Autonomous.h"
#include "CommandBase.h"
#include "Commands/MoveGrabberArms.h"
#include "Commands/MoveGrabberWheels.h"
#include "Potentiometers.h"
#include <iostream>

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
		SmartDashboard::PutNumber("Grabber Pot Value", GrabberPotentiometer().Get());
		SmartDashboard::PutNumber("Launcher Pot Value", LauncherPotentiometer().Get());
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TestPeriodic() {
		lw->Run();
	}
	
	virtual void DisabledInit(){
		std::cout<<"Start Disabled";
		static bool grabberInitialized = false;
		double samplesTotal;
		double averageSample;
		const int numSamples = 10;
		for(int i = 0; i < numSamples; ++i)
		{
			samplesTotal+= GrabberPotentiometer().Get();
		}
		averageSample = samplesTotal / numSamples;
		const double angleRange = 65;
		const double upRegisteringOffset = 5;
		const double downRegisteringOffset = 20;
		MoveGrabberArms::armUpAngle = averageSample - upRegisteringOffset;
		MoveGrabberArms::armDownAngle = (averageSample - angleRange) + downRegisteringOffset;
		grabberInitialized = true;
		std::cout<<"Disabled Initialized\nArmUpAngle:"<<MoveGrabberArms::armUpAngle<<"\n";
		std::cout<<"ArmDownAngle:"<<MoveGrabberArms::armDownAngle<<"\n";
	}
};

START_ROBOT_CLASS(Robot2014);

