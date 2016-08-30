#ifndef IRSLAVE_H
#define IRSLAVE_H

class IRSlave {
public:
	IRSlave(uint8_t powerPin, uint8_t clockPin, uint8_t latchPin, uint8_t dataPin, uint8_t sensorCount);
	~IRSlave();

	uint8_t getBest();
	uint8_t getAngle();

	void refresh();
private:
	uint8_t _powerPin;
	uint8_t _clockPin;
	uint8_t _latchPin;
	uint8_t _dataPin;

	uint8_t _sensorCount;

	uint8_t _best;
	uint8_t _angle;
};

#endif /* IRSLAVE_H */