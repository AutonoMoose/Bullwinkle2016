#ifndef IRSLAVE_H
#define IRSLAVE_H

class IRSlave {
public:
	IRSlave(uint8_t powerPin, uint8_t clockPin, uint8_t latchPin, uint8_t dataPin, uint8_t sensorCount);
	~IRSlave();

	uint8_t getBest() { return _best; }

	void refresh();
private:
	// Pin Configuration
	uint8_t _powerPin;
	uint8_t _clockPin;
	uint8_t _latchPin;
	uint8_t _dataPin;

	// Shift-In Configuration
	uint _sensorCount;
	uint _maxPulseLength = 255;
	uint _byteCount;
	uint _bitArray[];

	// Outputs
	uint8_t _best;
};

#endif /* IRSLAVE_H */