#include "Arduino.h"
#include "SenseLight.h"

SenseLight::SenseLight(uint8_t analogPin, uint8_t enablePin): _analogPin(analogPin), _enablePin(enablePin) {
	pinMode(_analogPin, INPUT);
	pinMode(_enablePin, OUTPUT);
}

SenseLight::~SenseLight() { /* NOTHING TO DECONSTRUCT */ }

void SenseLight::refresh() {
	digitalWrite(_enablePin, _isEnabled);
	_value = analogRead(_analogPin) / 4;
}