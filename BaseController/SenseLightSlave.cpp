#include "Arduino.h"
#include "SenseLightSlave.h"

SenseLightSlave::SenseLightSlave(uint8_t analogPin, uint8_t enablePin): _analogPin(analogPin), _enablePin(enablePin) {
	pinMode(_analogPin, INPUT);
	pinMode(_enablePin, OUTPUT);
}

SenseLightSlave::~SenseLightSlave() { /* NOTHING TO DECONSTRUCT */ }

void SenseLightSlave::refresh() {
	digitalWrite(_enablePin, _isEnabled);
	_value = analogRead(_analogPin) / 4;
}