#ifndef SENSELIGHTSLAVE_H
#define SENSELIGHTSLAVE_H

class SenseLightSlave {
public:
	SenseLightSlave(uint8_t analogPin, uint8_t enablePin);
	~SenseLightSlave();

	uint8_t get() { return _value; }

	void enable() { _isEnabled = true; }
	void disable() { _isEnabled = false; }

	void refresh();
private:
	uint8_t _analogPin;
	uint8_t _enablePin;

	bool _isEnabled = true;

	uint8_t _value = 0;
};

#endif /* SENSELIGHTSLAVE_H */