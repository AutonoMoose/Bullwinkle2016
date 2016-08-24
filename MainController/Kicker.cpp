#include "Arduino.h"
#include "Kicker.h"

Kicker::Kicker(uint8_t pinSignal, uint8_t pinAnalog): _pinSignal(pinSignal), _pinAnalog(pinAnalog) {

}

Kicker::~Kicker() { /* NOTHING TO DECONSTRUCT */ }

void Kicker::kick() {
	_lastKick = millis();
}

bool Kicker::isKicking() {
	return millis() - _lastKick <= _power;
}

void Kicker::setPower(uint8_t value) {
	_power = value;
}

uint8_t getPower() {
	return _power;
}

void refresh() {
	digitalWrite(_pinSignal, isKicking());
}