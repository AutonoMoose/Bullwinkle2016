#include "Arduino.h"
#include "Timer.h"

Timer::Timer() {

}

Timer::~Timer() {}

void Timer::begin() {
	beginTime = millis();
}

long Timer::difference() {
	return beginTime - millis();
}