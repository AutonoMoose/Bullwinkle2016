#include "Arduino.h"
#include "SR04Slave.h"

SR04Slave::SR04Slave(uint8_t trigPin, uint8_t echoPin): _trigPin(trigPin), _echoPin(echoPin) {
	pinMode(_trigPin, OUTPUT);
	pinMode(_echoPin, INPUT);
}

SR04Slave::~SR04Slave() {/* NOTHING TO DECONSRUCT */ }

void SR04Slave::refresh() {
	digitalWrite(_trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(_trigPin, LOW);

	_value = constrain(pulseIn(_echoPin, HIGH) / 58, 0, 255);
}