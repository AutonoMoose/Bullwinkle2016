#include "Arduino.h"
#include "IRSlave.h"

IRSlave::IRSlave(uint8_t powerPin, uint8_t clockPin, uint8_t latchPin, uint8_t dataPin, uint8_t sensorCount): _powerPin(powerPin), _clockPin(clockPin), _latchPin(latchPin), _dataPin(dataPin), _sensorCount(sensorCount) {

}

IRSlave::~IRSlave() {

}

uint8_t IRSlave::getBest() {
	return _best;
}

uint8_t IRSlave::getAngle() {
	return _angle;
}

IRSlave::refresh() {

}