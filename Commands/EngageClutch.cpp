#include "EngageClutch.h"

const double kWheelDiameter = 1;
const int kPulsesPerRotation = 500;
const double PI = 3.1415926535;

EngageClutch::EngageClutch()
	:CommandBase("EngageClutch"),
	 encoder(3, 2)
{
	Requires(launcher);
	//double distancePerPulse = kWheelDiameter * PI / kPulsesPerRotation;
	//encoder.SetDistancePerPulse(distancePerPulse);
	//encoder.SetMinRate(distancePerPulse * 4);
	//encoder.Start();
	SetTimeout(1);
}

void EngageClutch::Initialize()
{
	
}


void EngageClutch::Execute()
{
	//if(!encoder.GetStopped()) return;
	//launcher->RunMotor(.25);
	launcher->EngageClutch();
}

void EngageClutch::End()
{
	launcher->StopMotor();
}

void EngageClutch::Interrupted()
{
	End();
}

bool EngageClutch::IsFinished()
{
	//return encoder.GetStopped();
	return IsTimedOut();
}
