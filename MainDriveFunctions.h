void setDriveSpeeds (int lf, int rf, int lr, int rr, unsigned int time = 0) {
	motor[driveLeftFront] = lf;
	motor[driveLeftRear] = lr;
	motor[driveRightFront] = rf;
	motor[driveRightRear] = rr;

	if (time > 0) {
		wait1Msec (time);

		motor[driveLeftFront] = 0;
		motor[driveLeftRear] = 0;
		motor[driveRightFront] = 0;
		motor[driveRightRear] = 0;
	}
}

void tank4 () {
	int left = vexRT[Ch3];
	int right = vexRT[Ch2];

	setDriveSpeeds (left, right, left, right);
}
