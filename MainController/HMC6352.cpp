#include "HMC6352.h"

HMC6352::HMC6352() {
	Wire.begin();
}

HMC6352::~HMC6352() { /* NOTHING TO DECONSTRUCT */ }

void HMC6352::setHeading() {
	refresh();
	_heading = getAngle();
}

float HMC6352::getAngle() {
	return _angle;
}

void HMC6352::refresh() {
	Wire.beginTransmission(_slaveAddress);	// Send command
	Wire.write("A");
	Wire.endTransmission();

	delayMicroseconds(75);	// The HMC6352 needs at least a 70us (microsecond) delay

	Wire.requestFrom(_slaveAddress, 2);	// Request the 2 bytes (MSB comes first)

	while (Wire.available()) {
		_MSB = Wire.read();
		_LSB = Wire.read();
	}
	_angle = ((_MSB >> 8 + _LSB) / 10 ) - _heading;		// Put the MSB and LSB together 
}