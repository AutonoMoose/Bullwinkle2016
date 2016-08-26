#ifndef SENSELIGHT_H
#define SENSELIGHT_H

class SenseLight {
public:
	SenseLight(uint8_t analogPin, uint8_t enablePin);
	~SenseLight();

	uint8_t get() { return _value; }

	void enable() { _isEnabled = true; }
	void disable() { _isEnabled = false; }

	void refresh();
private:
	uint8_t _analogPin;
	uint8_t _enablePin;

	bool _isEnabled = false;

	uint8_t _value = 0;
};

#endif /* SENSELIGHT_H */