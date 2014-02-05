#ifndef GRABBERARMS_H
#define GRABBERARMS_H
#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "../Direction.h"


class GrabberArms: public Subsystem  {
private:
	SpeedController* controller;
public:
	GrabberArms();
	void InitDefaultCommand();
	void MoveWheels(Direction direction);
	void StopWheels();
};

#endif 
