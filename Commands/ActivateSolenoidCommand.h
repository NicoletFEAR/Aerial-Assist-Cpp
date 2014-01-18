#ifndef EXAMPLE_COMMAND_H
#define EXAMPLE_COMMAND_H

#include<WPILib.h>

class ActivateSolenoid: public Command {
private:
	Solenoid solenoid; 
public:
	ActivateSolenoid(uint32_t channel);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
