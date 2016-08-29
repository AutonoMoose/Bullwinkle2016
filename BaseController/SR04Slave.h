#ifndef SR04SLAVE_H
#define SR04SLAVE_H

class SR04Slave {
public:
	SR04Slave(uint8_t trigPin, uint8_t echoPin);
	~SR04Slave();

	uint8_t get() { return _value; }

	void refresh();
private:
	uint8_t _trigPin;
	uint8_t _echoPin;

	uint8_t _value;
};

#endif /* SR04SLAVE_H */