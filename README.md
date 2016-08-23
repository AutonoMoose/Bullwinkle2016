# Rocky
Rocket "Rocky" J. Squirrel

Team AutonoMoose Goalie Robot

## Structure

Main Micro - Top Layer:
ATMEGA328P @ 5V / 16MHz

	<> I2C Master
	<> Bluetooth
	> Motor Driver Control
		> PWM/Direction
	< Compass (HMC6352)
	< Accelerometer (MMA7361)

Secondary Micro - Middle Layer:
ATTINY84 @ 5.5V / 20MHz

	<> I2C Slave
	< Shift-In register Interface (to gather data from IR sensors)

Secondary Micro - Bottom Layer:
ATMEGA328P @ 5V / 16MHz

	<> I2C Slave
	< Ultrasonic Sense
		> Trigger
		< Echo pulse length
	< Light Sense
