#include "LightGate.h"

LightGate::LightGate(uint8_t pinDigital): _pinDigital(pinDigital) {
	pinMode(_pinDigital, INPUT);
}

bool LightGate::get() {
	return _state;
}

void LightGate::refresh() {
	_state = digitalRead(_pinDigital);
}