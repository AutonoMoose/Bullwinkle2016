#include "Wire.h"
#include "Robot.h"
#include "L298.h"
#include "Kicker.h"
#include "SenseLightMaster.h"
#include "SR04Master.h"
#include "IRMaster.h"

// System
Robot Robot;

// Sensors
HMC6352 Compass;
SenseLightMaster LightLeft;
SenseLightMaster LightRight;
IRMaster IR;
SR04Master UltraLeft;
SR04Master UltraRight;

// Actuators
L298 MotorC(6, 5, 4);
L298 MotorB(9, 8, 7);
L298 MotorA(10, 13, 12);
Kicker Kicker(A1, A1);

float power = 0.3;

void setup() {
	Serial.begin(9600);
	Wire.begin();
}

void loop() {
	
	if (analogRead(A6) > 512) {
		Robot.setState(AUTONOMOUS);
	}
	else {
		Robot.setState(DISABLED);
	}

	Wire.requestFrom(1, 4);

	while (Wire.available()) {
		UltraLeft.set(Wire.read());
		UltraRight.set(Wire.read());

		LightLeft.set(Wire.read());
		LightRight.set(Wire.read());
	}

	Wire.requestFrom(2, 1);

	while(Wire.available()) {
		IR.setBest(Wire.read());
	}

	Robot.refresh();
	MotorRefresh();
}

void disabledInit() {
	MotorA.set(0);
	MotorB.set(0);
	MotorC.set(0);
}

void disabledPeriodic() {
	MotorA.set(0);
	MotorB.set(0);
	MotorC.set(0);
}

void testInit() {

}
void testPeriodic() {

}

void autonomousInit() {
}

void autonomousPeriodic() {
	/*
	if (LightLeft.get() > 190 && Ultrasonic < 5) {
		right(0.35, 0);
		MotorRefresh();
		delay(100);
	}
	else if (LightRight.get() > 190 && Ultrasonic < 5) {
		left(0.35, 0);
		MotorRefresh();
		delay(100);
	}*/
	/*else {*/
		/*
		if (GyroGet() < 30 || GyroGet() > 330) rotation = 0;
		else if (GyroGet() != 180) rotation = 1/(abs(GyroGet() - 180));
		else rotation = 1;
		//rotation = 0;
		power = 0.4;
		if ((rotation+power) > 1) {
			power = 1 - rotation;
		}
		if (IR.getBest() < 4 || IR.getBest() > 20) {
			forwards(power, rotation);
		}
		else if (IR.getBest() <= 20 && IR.getBest() > 15) {
			left(power, rotation);
		}
		else if (IR.getBest() <= 9 && IR.getBest() >= 4) {
			right(power, rotation);
		}
		else if (IR.getBest() <= 15 && IR.getBest() > 9){
			backwards(power, rotation);
		}
		*/


		/*
		*
		*
		*	WORKING CODE!
		*
		*
		*/
		power = 0.4;
		rotation = 0;
		if (GyroGet() < 20 || GyroGet() > 340){
			if (IR.getBest() < 4 || IR.getBest() > 20) {
				forwards(power, rotation);
				currentTime = millis();
			}
			else if (IR.getBest() <= 20 && IR.getBest() > 15) {
				left(power, rotation);
			}
			else if (IR.getBest() <= 9 && IR.getBest() >= 4) {
				right(power, rotation);
			}
			else if (IR.getBest() <= 15 && IR.getBest() > 9){
				backwards(power, rotation);
			}
			else {
				forwards(power, rotation);
			}
		}
		else if (GyroGet() > 180) rotate(0.3);
		else rotate (-0.3);	
}


void left(float power, float rotation) {
	MotorA.set((power-0.1)+rotation);
	MotorB.set((power-0.1)-rotation);
	MotorC.set(-(power-0.1)-rotation);
}
void right(float power, float rotation) {
	MotorA.set(-(power-0.1)+rotation);
	MotorB.set(-(power-0.1)-rotation);
	MotorC.set((power-0.1)-rotation);
}
void forwards(float power, float rotation) {
	MotorA.set(power+rotation);
	MotorB.set(power-rotation);
	MotorC.set(0.0);
}
void backwards(float power, float rotation) {
	MotorA.set(-power+rotation);
	MotorB.set(-power-rotation);
	MotorC.set(0.0);
}
void rotate(float rotation){
	MotorA.set(rotation);
	MotorB.set(rotation);
	MotorC.set(rotation);
}

void MotorRefresh() {
	MotorA.refresh();
	MotorB.refresh();
	MotorC.refresh();
}

void CompassRefresh() {

}

void CompassGet() {

}