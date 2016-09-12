#include <PixyI2C.h> // Pixy CMU Cam (I2C)
#include "Robot.h" // Control System
#include "Wire.h" // I2C Communication
#include "L298.h" // Motor Controller
#include "Kicker.h" // Kicker Controller
#include "HMC6352.h" // Compass
#include "SR04Master.h" // Ultrasonic
#include "SenseLightMaster.h" // Light Sensor
#include "IRMaster.h" // IR Sensors

// System Control
Robot Robot;

// Actuators
L298 MotorA(3, 2, 4); // PWM, dirA, dirB
L298 MotorB(5, 7, 8);
L298 MotorC(6, 9, 10);
Kicker Kicker(11, A1); // Signal, Analog

// Sensors
SR04Master UltraA;
SR04Master UltraB;
SR04Master UltraC;
SR04Master UltraD;
SenseLightMaster LightA; // Analog Input, Enable Output
SenseLightMaster LightB; // Front Right
SenseLightMaster LightC; // Back Left
SenseLightMaster LightD; // Back Right
IRMaster IR;

HMC6352 Compass;

const uint8_t BUTTON_START = 13;
const uint8_t BUTTON_STOP = 12;

void setup() {
	Wire.begin(127);
	// Sensor Initialization
	Compass.setHeading();
	Kicker.setPower(200);
}

void disabledInit() {
	MotorA.disable();
	MotorB.disable();
	MotorC.disable();
}

void disabledPeriodic() {
}

void testInit() {

}

void testPeriodic() {

}

void autonomousInit() {
	MotorA.enable();
	MotorB.enable();
	MotorC.enable();
}

void autonomousPeriodic() {
	// Update Sensors
	Wire.requestFrom(1, 8);
	while (Wire.available()) {
		LightA.set(Wire.read()); // These may need to be reversed
		LightB.set(Wire.read());
		LightC.set(Wire.read());
		LightC.set(Wire.read());

		UltraA.set(Wire.read());
		UltraB.set(Wire.read());
		UltraC.set(Wire.read());
		UltraD.set(Wire.read());
	}

	Wire.requestFrom(2, 2);
	while (Wire.available()) {
		IR.setBest(Wire.read());
		IR.setBestAngle(Wire.read());
	}

	Compass.refresh();

	// Decide what to do

	/* This is where Reilly does his magic */
	
	Kicker.kick();

	// Refresh (comment to disable functionality)
	Kicker.refresh();
	MotorA.refresh();
	MotorB.refresh();
	MotorC.refresh();
}

void loop() {

}