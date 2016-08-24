#include "Arduino.h"
#include "L298.h"

L298::L298(uint8_t pinSpeed, uint8_t pinDirA, uint8_t pinDirB): _pinSpeed(pinSpeed), _pinDirA(pinDirA), _pinDirB(pinDirB) {
	pinMode(_pinSpeed, OUTPUT);
	pinMode(_pinDirA, OUTPUT);
	pinMode(_pinDirB, OUTPUT);
}

L298::~L298() { /* NOTHING TO DECONSTRUCT */ }

void L298::set(float value) {
	_value = _value;

	if (value >= 0) {									// Set Direction
		digitalWrite(_pinDirA, !_isInverted);
		digitalWrite(_pinDirB, _isInverted);
	}
	else {
		digitalWrite(_pinDirA, _isInverted);
		digitalWrite(_pinDirB, !_isInverted);
	}

	analogWrite(_pinSpeed, uint8_t(fabs(_value)*255)); 	// Write Speed
}

float L298::get() {
	return _value;
}

void L298::setInverted(bool value) {
	_isInverted = value;
}

bool L298::getInverted() {
	return _isInverted;
}