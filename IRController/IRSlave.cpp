#include "Arduino.h"
#include "IRSlave.h"

IRSlave::IRSlave(uint8_t powerPin, uint8_t clockPin, uint8_t latchPin, uint8_t dataPin, uint8_t sensorCount): _powerPin(powerPin), _clockPin(clockPin), _latchPin(latchPin), _dataPin(dataPin), _sensorCount(sensorCount) {
	_byteCount = ceil(_sensorCount / 8);
	uint _bitArray[_sensorCount];
}

IRSlave::~IRSlave() { /* NOTHING TO DECONSTRUCT */ }

void IRSlave::refresh() {
	// Power Cycle
	digitalWrite(_powerPin, LOW);
	delay(2);
	digitalWrite(_powerPin, HIGH);

	// Shift Data In
	for (uint pulse = 0; pulse < _maxPulseLength; ++pulse) {
		// Latching
		digitalWrite(_clockPin, HIGH); // Set Clock State
		digitalWrite(_latchPin, LOW);
		digitalWrite(_latchPin, HIGH);

		// Bit Shifting
		for (uint byte = 0; byte < _byteCount; ++_byteCount) {
			uint8_t currentByte = shiftIn(_dataPin, _clockPin, MSBFIRST);

			for (uint bit = 0; bit < 8; ++bit) {
				if (bit + (byte * 8) > _sensorCount) {
					_bitArray[bit + (byte * 8)] = bitRead(currentByte, bit);	
				}
				else { break; }
			}
		}
	}

	_best = 0; // Reset best

	// Find Best
	for (uint i = 0; i < _sensorCount; i++) {
		if (_bitArray[i] > _best) {
			_best = i;
		}
	}
}