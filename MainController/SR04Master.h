#ifndef SR04MASTER_H
#define SR04MASTER_H

class SR04Master {
public:
	SR04Master();
	~SR04Master();

	uint8_t get() { return _value; }

	void set(uint8_t value) { _value = value; }
private:
	uint8_t _value;
};

#endif /* SR04MASTER_H */