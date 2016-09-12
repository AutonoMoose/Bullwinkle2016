#ifndef ROBOT_H
#define ROBOT_H

void disabledInit();
void disabledPeriodic();
void testInit();
void testPeriodic();
void autonomousInit();
void autonomousPeriodic();

class Robot {
public:
	enum rState_t { DISABLED, TEST, AUTONOMOUS, NUM_STATES };
	enum rSensorType_t { SENSELIGHT, SR04, IR, LIGHTGATE };

	Robot();
	~Robot();

	void setState(rState_t state);
	uint8_t getState();

	void refresh();
private:
	rState_t rState = DISABLED;
	bool rStateChanged = false;
};

#endif /* ROBOT_H */
