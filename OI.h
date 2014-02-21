#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include <vector>

class OI {
private:
	GenericHID* driveController;
	GenericHID* gameMechController;
	std::vector<Button*> buttons;
	typedef void (Button::*RegistrationMethod)(Command*); //Registration Method is a pointer to a member function on Button
	/*
	 * @param button: The button to register the command on
	 * @param command: The command to register
	 * @param registrar: The method to use to register (syntax is &Button::nameOfRegistrationMethod )
	 */
	void InitializeButton(Button* button, Command* command, RegistrationMethod registrar);
public:
	OI();
	GenericHID* DriveController();
};

#endif
