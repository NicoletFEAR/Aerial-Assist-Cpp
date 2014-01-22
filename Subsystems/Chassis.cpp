#include "Chassis.h"
#include "../Commands/TeleOpDrive.h"

#include "../Robotmap.h"

Chassis::Chassis() : Subsystem("Chassis"),
	leftFrontMotor(new Jaguar(kLeftFrontMotor)),
	rightFrontMotor(new Jaguar(kRightFrontMotor)),
	leftRearMotor(new Jaguar(kLeftRearMotor)),
	rightRearMotor(new Victor(kRightRearMotor)),
	robotDrive(leftFrontMotor, leftRearMotor, rightFrontMotor, rightRearMotor)
{
	
}
    
void Chassis::InitDefaultCommand()
{
	SetDefaultCommand(new TeleOpDrive());
}
