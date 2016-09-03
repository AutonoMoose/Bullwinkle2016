#include "Arduino.h"
#include "SR04Slave.h"

SR04Slave::SR04Slave(uint8_t trigPin, uint8_t echoPin): _trigPin(trigPin), _echoPin(echoPin) {
	pinMode(_trigPin, OUTPUT);
	pinMode(_echoPin, INPUT);
}

SR04Slave::~SR04Slave() {/* NOTHING TO DECONSRUCT */ }

void SR04Slave::refresh() {
	digitalWrite(_trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(_trigPin, HIGH);
	delayMicroseconds(5);
	digitalWrite(_trigPin, LOW);

	_value = pulseIn(_echoPin, HIGH, 2900) / 58; // Limit to 2900 micro seconds
}