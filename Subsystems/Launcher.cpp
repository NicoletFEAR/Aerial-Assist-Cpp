#include "Launcher.h"
#include "../Robotmap.h"
#include <cmath>
#include "../Commands/EngageClutch.h"

Launcher::Launcher()
	:Subsystem("Launcher"),
	 chargingMotor(new Victor(kChargingMotor)),
	 disengageClutchSolenoid(kDisengageSolenoid),
	 engageClutchSolenoid(kEngageSolenoid)
{
	
}


void Launcher::InitDefaultCommand()
{
	SetDefaultCommand(new ::EngageClutch());
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
