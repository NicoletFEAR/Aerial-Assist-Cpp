#pragma once
#include "WPILib.h"

class Launcher : public Subsystem
{
private:
	SpeedController* chargingMotor;
	Solenoid disengageClutchSolenoid;
	Solenoid engageClutchSolenoid;
public:
	Launcher();
	void InitDefaultCommand();
	void RunMotor(float speed);
	void StopMotor();
	void ReleaseClutch();
	void EngageClutch();
};
