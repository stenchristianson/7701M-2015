void setDriveSpeeds (int lf, int rf, int lr, int rr, unsigned int time = 0) {
	motor[driveLeftFront] = lf;
	motor[driveLeftRear] = lr;
	motor[driveRightFront] = rf;
	motor[driveRightRear] = rr;

	if (time > 0) {
		wait1Msec (time);

		setDriveSpeeds (0,0,0,0);
	}
}
