#include "IR.h"

IR IR(A7, 8, 9, 7, 19); // Power Pin, Clock Pin, Latch Pin, Data Pin, Sensor Count

void setup() {
	Wire.begin(2);
	Wire.onRequest(dataRequest);
}

void loop() {
	IR.refresh();
}

void dataRequest() {
	Wire.write(IR.getBest());
}