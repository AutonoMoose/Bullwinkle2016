#include "SenseLightMaster.h"

SenseLightMaster::SenseLightMaster() {
}

SenseLightMaster::~SenseLightMaster() { /* NOTHING TO DECONSTRUCT */ }

uint8_t SenseLightMaster::get() {
	return _value;
}

void SenseLightMaster::set(uint8_t value) {
	_value = value;
}