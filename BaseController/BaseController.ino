#include "Wire.h"
#include "SenseLight.h"
#include "SR04.h"

SR04 UltraA(3, 2); // Front Left
SR04 UltraB(5, 4); // Front Right
SR04 UltraC(7, 6); // Back Left
SR04 UltraD(9, 8); // Back Right

SenseLight LightA(A0, A6); // Front Left
SenseLight LightB(A1, A6); // Front Right
SenseLight LightC(A2, A6); // Back Left
SenseLight LightD(A3, A6); // Back Right

void setup() {
	Wire.begin(4);
	Wire.onRequest(dataRequest);
}

void loop() {
	UltraA.refresh();
	UltraB.refresh();
	UltraC.refresh();
	UltraD.refresh();

	LightA.refresh();
	LightB.refresh();
	LightC.refresh();
	LightD.refresh();
}

void dataRequest() {
	Wire.write(UltraA.get()); // Respond with 8 bytes of data
	Wire.write(UltraB.get());
	Wire.write(UltraC.get());
	Wire.write(UltraD.get());

	Wire.write(LightA.get());
	Wire.write(LightB.get());
	Wire.write(LightC.get());
	Wire.write(LightD.get());
}