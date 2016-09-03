#ifndef LIGHTGATE_H
#define LIGHTGATE_H

#include "Arduino.h"

class LightGate {
public:
	LightGate(uint8_t pinDigital);

	bool get();

	void refresh();
private:
	uint8_t _pinDigital;

	bool _state;
};

#endif /* LIGHTGATE_H */