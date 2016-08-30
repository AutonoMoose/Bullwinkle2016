#include "Arduino.h"
#include "Robot.h"

Robot::Robot() {

}

Robot::~Robot() {

}

void Robot::setState(rState_t state) {
	rStateChanged = true;
}

uint8_t Robot::getState() {
	return rState;
}

void Robot::refresh() {
	if (rStateChanged) {
		rStateChanged = false;
		switch (rState) {
			case DISABLED:		disabledInit(); break;
			case TEST:			testInit(); break;
			case AUTONOMOUS:	autonomousInit(); break;
		}
	}
	else {
		switch (rState) {
			case DISABLED:		disabledPeriodic(); break;
			case TEST:			testPeriodic(); break;
			case AUTONOMOUS:	autonomousPeriodic(); break;
		}
	}
}