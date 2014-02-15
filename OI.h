#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	GenericHID* driveController;
public:
	OI();
	GenericHID* DriveController();
};

#endif
