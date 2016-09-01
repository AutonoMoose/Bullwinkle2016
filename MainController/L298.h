#ifndef L298_H
#define L298_H

#include "Arduino.h"

class L298 {
public:
	L298(uint8_t pinSpeed, uint8_t pinDirA, uint8_t pinDirB);
	~L298();

	void set(float value);
	float get();

	void setInverted(bool value);
	bool getInverted();

	void enable();
	void disable();
	void refresh();
private:
	uint8_t _pinSpeed;
	uint8_t _pinDirA;
	uint8_t _pinDirB;
	
	float _value; // speed

	bool _isInverted = false;
};

#endif /* L298_H */