#ifndef IRMASTER_H
#define IRMASTER_H

class IRMaster {
public:
	IRMaster();
	~IRMaster();

	uint8_t getBest() { return _best; }
	uint8_t getBestAngle() { return _bestAngle; }

	void setBest(uint8_t value) { _best = value; }
	void setBestAngle(uint8_t value ) { _bestAngle = value; }
private:
	uint8_t _best;
	uint8_t _bestAngle;
};

#endif /* IRMASTER_H */