#include "IRSlave.h"
#include "Wire.h"

IRSlave IR(A7, 8, 9, 7, 19); // Power Pin, Clock Pin, Latch Pin, Data Pin, Sensor Count

void setup() {
	Wire.begin(2);
	Wire.onRequest(onRequest);
}

void loop() {
	IR.refresh();
}

void onRequest() {
	Wire.write(IR.getBest());
}