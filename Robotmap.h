#ifndef ROBOTMAP_H
#define ROBOTMAP_H


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// #define LEFTMOTOR 1
// #define RIGHTMOTOR 2

const int kLeftFrontMotor = 1;//These are PWM channels
const int kRightFrontMotor = 2;
const int kLeftRearMotor = 3;
const int kRightRearMotor = 4;
const int kChargingMotor = 5;
const int kLauncherLimitSwitch = 9; // These are relay channels
const int kDisengageSolenoid = 1;
const int kEngageSolenoid = 2;
const uint32_t kPressureSwitchChannel = 2;
const uint32_t kCompressorRelayChannel = 4;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// #define RANGE_FINDER_PORT 1
// #define RANGE_FINDER_MODULE 1

#endif
