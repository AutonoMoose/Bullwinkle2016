#include "IR.h"

IR::IR(uint8_t powerPin, uint8_t clockPin, uint8_t latchPin, uint8_t _dataPin): _powerPin(powerPin), _clockPin(clockPin), _latchPin(latchPin), _dataPin(_dataPin) {
	_byteCount = ceil(IR_SENSOR_COUNT / 8);

	pinMode(_latchPin, OUTPUT);
	pinMode(_clockPin, OUTPUT);
	pinMode(_dataPin, INPUT);
	pinMode(_powerPin, OUTPUT);
}

IR::~IR() { /* NOTHING TO DECONSTRUCT */ }

void IR::refresh() {
	digitalWrite(A6, HIGH);
	delay(5);
	digitalWrite(A6, LOW);

	for (int i = 0; i < IR_SENSOR_COUNT; i++) {
		_dataArray[i] = 0;
	}

	for (int i = 0; i < 350; i++) {
		// pulse the latch to load the data
		digitalWrite(_clockPin, HIGH);
		digitalWrite(_latchPin, LOW);
		digitalWrite(_latchPin, HIGH);

		// Shift Data In
		_rawDataArray[0] = shiftIn(_dataPin, _clockPin, MSBFIRST);
		_rawDataArray[1] = shiftIn(_dataPin, _clockPin, MSBFIRST);
		_rawDataArray[2] = shiftIn(_dataPin, _clockPin, MSBFIRST);

		// print pin data to serial monitor
		for (int b = 0; b < 8; b++) {
			_dataArray[b] += !bitRead(_rawDataArray[0], b);
		}
		for (int b = 0; b < 8; b++) {
			_dataArray[b+8] += !bitRead(_rawDataArray[1], b);
		}
		for (int b = 0; b < 8; b++) {
			_dataArray[b+16] += !bitRead(_rawDataArray[2], b);
		}
	}

	_best = 0; // Reset Best

	for (int i = 0; i < IR_SENSOR_COUNT; i++) {
		if (_dataArray[i] > _dataArray[_best] and !(_dataArray[i] == 350)) {
			_best = i;
		}
		Serial.print(_dataArray[i]);
		Serial.print(", ");
	}
	Serial.println();
}