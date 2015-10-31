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

	setDriveSpeeds (left, right, left, right);
}
