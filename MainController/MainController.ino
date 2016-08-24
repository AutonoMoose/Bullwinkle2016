
enum state_t {
	STARTUP,
	STANDBY,
	RUNNING,
	STOPING,
	NUM_STATES
};

void setup() {

}

void loop() {

	switch(ROBOT_STATE) {
		case STARTUP: 	setup(); break;
		case STANDBY: 	standby(); break;
		case RUNNING: 	running(); break;
		case STOPING: 	stopping(); break;
	}
}