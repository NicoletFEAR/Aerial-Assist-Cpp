#include "Launcher.h"
#include "../Robotmap.h"
#include <cmath>

Launcher::Launcher()
	:Subsystem("Launcher"),
	 chargingMotor(new Victor(kChargingMotor)),
	 clutchServo(kClutchServo)
{
	
}


void Launcher::InitDefaultCommand()
{
}

void Launcher::RunMotor(float speed)
{
	speed = std::abs(speed);
	chargingMotor->Set(speed);
}

void Launcher::StopMotor()
{
	chargingMotor->Set(0);
}

void Launcher::ReleaseClutch()
{
	clutchServo.SetAngle(Servo::GetMaxAngle());
}

void Launcher::EngageClutch()
{
	clutchServo.SetAngle(Servo::GetMinAngle());
}
