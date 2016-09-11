#ifndef SENSELIGHTMASTER_H
#define SENSELIGHTMASTER_H

#include "Arduino.h"

class SenseLightMaster {
public:
	SenseLightMaster();
	~SenseLightMaster();

	uint8_t get();

	void set(uint8_t value);

	void refresh();
private:
	uint8_t _pinAnalog;
	uint8_t _pinEnable;

	uint8_t _value = 0;
};

#endif /* SENSELIGHTMASTER_H */