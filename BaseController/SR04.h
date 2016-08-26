#ifndef SR04_H
#define SR04_H

class SR04 {
public:
	SR04(uint8_t trigPin, uint8_t echoPin);
	~SR04();

	uint8_t get() { return _value; }

	void refresh();
private:
	uint8_t _trigPin;
	uint8_t _echoPin;

	uint8_t _value;
};

#endif /* SR04_H */