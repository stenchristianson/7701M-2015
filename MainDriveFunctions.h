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

void driveTank () {
	int left = vexRT[Ch3];
	int right = vexRT[Ch2];

	setDriveSpeeds (left, right, left, right);
}

void driveTime (int left = 0, int right = 0, int time = 0) {
	if      (left >= 1 && right >= 1) setDriveSpeeds (127, 127, 127, 127, time);
	else if (left >= 1 && right == 0) setDriveSpeeds (127, 0, 127, 0, time);
	else if (left >= 1 && right <= 1) setDriveSpeeds (127, -127, 127, -127, time);
	else if (left == 0 && right >= 1) setDriveSpeeds (0, 127, 0, 127, time);
	else if (left == 0 && right == 0) setDriveSpeeds (0, 0, 0, 0, time);
	else if (left == 0 && right <= 0) setDriveSpeeds (0, -127, 0, -127, time);
	else if (left <= 1 && right >= 1) setDriveSpeeds (-127, 127, -127, 127, time);
	else if (left <= 1 && right == 0) setDriveSpeeds (-127, 0, -127, 0, time);
	else if (left <= 1 && right <= 1) setDriveSpeeds (-127, -127, -127, -127, time);
	else writeDebugStreamLine ("Error: driveTime(int left, int right, int time): Invalid Parameters");
}
