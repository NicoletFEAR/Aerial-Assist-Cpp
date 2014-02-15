#include "Chassis.h"
#include "../Commands/TeleOpDrive.h"
#include "../Robotmap.h"

Chassis::Chassis() : Subsystem("Chassis"),
	leftFrontMotor(new Victor(kLeftFrontMotor)),
	rightFrontMotor(new Victor(kRightFrontMotor)),
	leftRearMotor(new Victor(kLeftRearMotor)),
	rightRearMotor(new Victor(kRightRearMotor)),
	driveSystem(leftFrontMotor, leftRearMotor, rightFrontMotor, rightRearMotor)
{
	driveSystem.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	driveSystem.SetInvertedMotor(RobotDrive::kRearRightMotor, true);
}
    
void Chassis::InitDefaultCommand()
{
	SetDefaultCommand(new TeleOpDrive());
}

void Chassis::Drive(float x, float y, float turn, float gyroAngle)
{
	driveSystem.MecanumDrive_Cartesian(x, y, turn, gyroAngle);
}
