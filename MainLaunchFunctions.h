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

task accelFlyWheel () {

}

void manageAccelFlyWheelTask () {

}
