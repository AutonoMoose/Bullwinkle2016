#include "IRSlave.h"

IRSlave IR(6, 7, 8, 9, 24); // Power Pin, Clock Pin, Latch Pin, Data Pin, Sensor Count

void setup() {
	Wire.begin(2);
	Wire.onRequest(onRequest);
}

void loop() {
	IR.refresh();
}

void onRequest() {
	Wire.write(IR.getBest());
	Wire.write(IR.getAngle);
}