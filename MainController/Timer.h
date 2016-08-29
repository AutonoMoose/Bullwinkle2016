#ifndef TIMER_H
#define TIMER_H

class Timer {
public:
	Timer();
	~Timer();

	void begin();
	long difference();
private:
	long beginTime;

};

#endif /* TIMER_H */