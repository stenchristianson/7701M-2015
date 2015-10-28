#define FLYWHEEL_ACCELERATION 10

void setConveyorSpeeds (signed int speed, int time = 0) {
	motor[convLeft] = speed;
	motor[convRight] = speed;

	if (time > 0) {
		wait1Msec(time);
		motor[convLeft] = 0;
		motor[convRight] = 0;
	}
}

void setLaunchSpeeds (signed int speed, int time = 0) {
	motor[flyLeft] = speed;
	motor[flyRight] = speed;

	if (time > 0) {
		wait1Msec(time);
		motor[flyLeft] = 0;
		motor[flyRight] = 0;
	}
}
