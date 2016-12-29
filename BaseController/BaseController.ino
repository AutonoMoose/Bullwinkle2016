#include "Wire.h"
#include "SenseLightSlave.h"
#include "SR04Slave.h"

SR04Slave UltraA(A3, A2); // Front Left
SR04Slave UltraB(5, 4); // Front Right

SenseLightSlave LightA(A1, 9); // Front Left
SenseLightSlave LightB(A0, 9); // Front Right

void setup() {
	Wire.begin(1);
	Wire.onRequest(requestEvent);
}

void loop() {
	// Refresh all (in machete order)
	UltraA.refresh();
	LightA.refresh();
	UltraB.refresh();
	LightB.refresh();
}

void requestEvent() {
	Wire.write(UltraA.get());
	Wire.write(UltraB.get());

	Wire.write(LightA.get());
	Wire.write(LightB.get());
}