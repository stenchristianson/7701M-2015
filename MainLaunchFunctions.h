#define FLYWHEEL_ACCELERATION 10

void setConveyorSpeeds (signed int speed, int time = 0) {
	if (abs(speed) > MOTOR_DEADBAND) {
		motor[convLeft] = speed;
		motor[convRight] = speed;
	}
	else {
		motor[convLeft] = 0;
		motor[convRight] = 0;
	}

	if (time > 0) {
		wait1Msec(time);
		motor[convLeft] = 0;
		motor[convRight] = 0;
	}
}

void setLaunchSpeeds (signed int speed, int time = 0) {
	motor[flyLeft] = speed;
	motor[flyRight] = speed;

	if (abs(speed) > MOTOR_DEADBAND) {
		motor[flyLeft] = speed;
		motor[flyRight] = speed;
	}
	else {
		motor[flyLeft] = 0;
		motor[flyRight] = 0;
	}

	if (time > 0) {
		wait1Msec(time);
		motor[flyLeft] = 0;
		motor[flyRight] = 0;
	}
}
