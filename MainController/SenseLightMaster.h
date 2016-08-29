#ifndef SENSELIGHTMASTER_H
#define SENSELIGHTMASTER_H

class SenseLightMaster {
public:
	SenseLightMaster();
	~SenseLightMaster();

	uint8_t get();

	void set(uint8_t value);
private:
	uint8_t _value = 0;
};

#endif /* SENSELIGHTMASTER_H */