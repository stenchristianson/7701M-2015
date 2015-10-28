#define MAX_ELEV_LEFT 3000
#define MIN_ELEV_LEFT 1000
#define MAX_ELEV_RIGHT 3000
#define MIN_ELEV_RIGHT 1000

void setElevationSpeeds (int leftSpeed, int rightSpeed, int time = 0) {
	motor[elevLeft] = leftSpeed;
	motor[elevRight] = rightSpeed;

	if (time > 0) {
		wait1Msec (time);

		motor[elevLeft] = 0;
		motor[elevRight] = 0;
	}
}

void elevPot (int leftPot, int rightPot, float speed = 1) {
	bool leftOnTarget = false;
	bool rightOnTarget = false;

	int leftSpeed;
	int rightSpeed;

	int leftCurr = SensorValue[elevLeft];
	int rightCurr = SensorValue[elevRight];

	while (!leftOnTarget && !rightOnTarget) {
		if (leftCurr < leftPot) {
			leftSpeed = 127 * speed;
			leftOnTarget = false;
		}
		else if (leftCurr > leftPot) {
			leftSpeed = -127 * speed;
			leftOnTarget = false;
		}
		else {
			leftSpeed = 0;
			leftOnTarget = true;
		}

		if (rightCurr < rightPot) {
			rightSpeed = 127 * speed;
			rightOnTarget = false;
		}
		else if (rightCurr > rightPot) {
			rightSpeed = -127 * speed;
			rightOnTarget = false;
		}
		else {
			rightSpeed = 0;
			rightOnTarget = true;
		}

		setElevationSpeeds (leftSpeed, rightSpeed);
	}
}
