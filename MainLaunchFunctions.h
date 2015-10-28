void setConveyorSpeeds (signed int speed, int time = 0) {
	motor[convLeft] = speed;
	motor[convRight] = speed;

	if (time > 0) {
		wait1Msec(time);
		motor[convLeft] = 0;
		motor[convRight] = 0;
	}
}
