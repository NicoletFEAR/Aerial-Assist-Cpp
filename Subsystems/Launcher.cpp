#include "Launcher.h"
#include "../Robotmap.h"
#include <cmath>

Launcher::Launcher()
	:Subsystem("Launcher"),
	 chargingMotor(new Jaguar(kChargingMotor)),
	 clutchSolenoid(kClutchSolenoid)
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
	clutchSolenoid.Set(1);
}

void Launcher::EngageClutch()
{
	clutchSolenoid.Set(0);
}
