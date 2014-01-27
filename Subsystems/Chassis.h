#pragma once
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Chassis: public Subsystem
{
private:
	SpeedController* leftFrontMotor;
	SpeedController* rightFrontMotor;
	SpeedController* leftRearMotor;
	SpeedController* rightRearMotor;
	RobotDrive driveSystem;
public:
	Chassis();
	void InitDefaultCommand();
	void Drive(float x, float y, float turn, float gyroAngle = 0.0f);
};

