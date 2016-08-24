#ifndef KICKER_H
#define KICKER_H

#include "Arduino.h"

class Kicker {
public:
	Kicker(uint8_t pinSignal, uint8_t pinAnalog);
	~Kicker();

	void kick();
	bool isKicking();

	void setPower(uint8_t value);
	uint8_t getPower();
	
	void refresh();

private:
	uint8_t _pinSignal;
	uint8_t _pinAnalog;

	uint8_t _power;

	long _lastKick;
};

#endif /* KICKER_H */