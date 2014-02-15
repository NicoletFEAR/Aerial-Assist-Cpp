#include "Chassis.h"
#include "../Commands/TeleOpDrive.h"
#include "../Robotmap.h"

Chassis::Chassis() : Subsystem("Chassis"),
	leftFrontMotor(new Jaguar(kLeftFrontMotor)),
	rightFrontMotor(new Jaguar(kRightFrontMotor)),
	leftRearMotor(new Jaguar(kLeftRearMotor)),
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
