#include "Launcher.h"
#include "../Robotmap.h"
#include <cmath>

Launcher::Launcher()
	:Subsystem("Launcher"),
	 chargingMotor(new Jaguar(kChargingMotor)),
	 clutchServo(kClutchServo)
{
	
}


void Launcher::InitDefaultCommand()
{
}

void Launcher::RunMotor(float speed)
{
	speed = std::abs(speed);
	chargingMotor->Set(-speed);
}

void Launcher::StopMotor()
{
	chargingMotor->Set(0);
}

void Launcher::ReleaseClutch()
{
	clutchServo.SetAngle(180);
}

void Launcher::EngageClutch()
{
	clutchServo.SetAngle(0);
}
