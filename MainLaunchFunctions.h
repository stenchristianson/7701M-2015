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

////Task to accelerate the flywheel so as not to break the motors
//Definitions
#define MOTOR_MAX_VALUE 127
#define MOTOR_MIN_VALUE (-127)
#define FLY_ACCEL 10//In [motor units]/s/s

//Support function for accelFlyWheel, rounds a float to the nearest whole number
int round (float f) {
	return (f > 0) ? (int)(f + 0.5) : (int) (f - 0.5);
}

task accelFlyWheel () {
	int currLeft = motor[flyLeft];
	int currRight = motor[flyRight];

	int period = round (1000 / FLY_ACCEL);

	while (currLeft != flySpeed || currRight != flySpeed) {
		// Check left
		if (currLeft > flySpeed && currLeft > MOTOR_MIN_VALUE) currLeft--;
		else if (currLeft < flySpeed && currLeft < MOTOR_MAX_VALUE) currLeft++;

		//Check right
		if (currRight > flySpeed && currRight > MOTOR_MIN_VALUE) currRight--;
		else if (currRight < flySpeed && currRight < MOTOR_MAX_VALUE) currRight++;

		wait1Msec(period);

		if (period == 0) EndTimeSlice();
	}

}

void changeFlySpeed (int speed) {

}
