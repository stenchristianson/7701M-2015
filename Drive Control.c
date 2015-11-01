void setDriveSpeeds (int lf, int rf, int lr, int rr, unsigned int time = 0) {
	if (abs(lf) > MOTOR_DEADBAND) motor[driveLeftFront] = lf;
	else motor[driveLeftFront] = 0;
	if (abs(rf) > MOTOR_DEADBAND) motor[driveRightFront] = rf;
	else motor[driveRightFront] = 0;
	if (abs(lr) > MOTOR_DEADBAND) motor[driveLeftRear] = lr;
	else motor[driveLeftRear] = 0;
	if (abs(rr) > MOTOR_DEADBAND) motor[driveRightRear] = rr;
	else motor[driveRightRear] = 0;

	if (time > 0) {
		wait1Msec (time);

		motor[driveLeftFront] = 0;
		motor[driveLeftRear] = 0;
		motor[driveRightFront] = 0;
		motor[driveRightRear] = 0;
	}
}

void driveTank () {
	int left = vexRT[Ch3];
	int right = vexRT[Ch2];

	if (vexRT[Btn5U]) {
		left /= 2;
		right /= 2;
	}
	else if (vexRT[Btn5D]) {
		left /= 5;
		right /= 5;
	}

	setDriveSpeeds (left, right, left, right);
}

void setElevSpeeds (int leftSpeed, int rightSpeed, int time = 0) {
	if (abs(leftSpeed) > MOTOR_DEADBAND) motor[elevLeft] = leftSpeed;
	else motor[elevLeft] = 0;

	if (abs(rightSpeed) > MOTOR_DEADBAND) motor[elevRight] = rightSpeed;
	else motor[elevRight] = 0;

	motor[elevLeft] = leftSpeed;
	motor[elevRight] = rightSpeed;

	if (time > 0) {
		wait1Msec (time);

		motor[elevLeft] = 0;
		motor[elevRight] = 0;
	}
}

void elevJoystickControl () {
	if (vexRT[Btn8U]) {
		setElevSpeeds (127, 127);
	}
	else if (vexRT[Btn8D]) {
		setElevSpeeds (-127, -127);
	}
	else setElevSpeeds (0,0);
}
