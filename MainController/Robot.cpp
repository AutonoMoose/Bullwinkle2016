#include "Robot.h"

Robot::Robot() {

}

Robot::~Robot() {

}

void Robot::setState(rState_t state) {
	if (rState != state) {
		rStateChanged = true;
	}
	rState = state;
}

uint8_t Robot::getState() {
	return rState;
}

void Robot::refresh() {
	if (rStateChanged == true) {
		switch (rState) {
			case DISABLED:		disabledInit(); break;
			case TEST:			testInit(); break;
			case AUTONOMOUS:	autonomousInit(); break;
		}
		rStateChanged = false;
	}
	else {
		switch (rState) {
			case DISABLED:		disabledPeriodic(); break;
			case TEST:			testPeriodic(); break;
			case AUTONOMOUS:	autonomousPeriodic(); break;
		}
	}
}