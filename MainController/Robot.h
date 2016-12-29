#ifndef ROBOT_H
#define ROBOT_H

#include "Arduino.h"

void disabledInit();
void disabledPeriodic();
void testInit();
void testPeriodic();
void autonomousInit();
void autonomousPeriodic();

enum rState_t { DISABLED, TEST, AUTONOMOUS, NUM_STATES };

class Robot {
public:

	Robot();
	~Robot();

	void setState(rState_t state);
	uint8_t getState();

	uint8_t getStateChanged() { return rStateChanged; }

	void refresh();
private:
	rState_t rState = DISABLED;
	bool rStateChanged = true;
};

#endif /* ROBOT_H */
