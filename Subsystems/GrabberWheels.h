#ifndef GRABBERWHEELS_H
#define GRABBERWHEELS_H
#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "../Direction.h"


class GrabberWheels: public Subsystem  {
private:
	SpeedController* controller;
public:
	GrabberWheels();
	void InitDefaultCommand();
	void MoveWheels(Direction direction);
	void StopWheels();
};

#endif 
