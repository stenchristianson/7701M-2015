void setElevationSpeeds (int leftSpeed, int rightSpeed, int time = 0) {
	motor[elevLeft] = leftSpeed;
	motor[elevRight] = rightSpeed;

	if (time > 0) {
		wait1Msec (time);

		motor[elevLeft] = 0;
		motor[elevRight] = 0;
	}
}
