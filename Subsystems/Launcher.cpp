#include "Launcher.h"
#include "../Robotmap.h"
#include <cmath>

Launcher::Launcher()
	:Subsystem("Launcher"),
	 chargingMotor(new Jaguar(kChargingMotor)),
	 disengageClutchSolenoid(kDisengageSolenoid),
	 engageClutchSolenoid(kEngageSolenoid)
{
	
}


void Launcher::InitDefaultCommand()
{
	disengageClutchSolenoid.Set(false);
	engageClutchSolenoid.Set(true);
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
	disengageClutchSolenoid.Set(true);
	engageClutchSolenoid.Set(false);
}

void Launcher::EngageClutch()
{
	disengageClutchSolenoid.Set(false);
	engageClutchSolenoid.Set(true);
}
