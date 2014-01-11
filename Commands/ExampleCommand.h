#ifndef EXAMPLE_COMMAND_H
#define EXAMPLE_COMMAND_H

#include<WPILib.h>

class ExampleCommand: public Command {
public:
	ExampleCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
