#define MAX_ELEV_LEFT 3000
#define MIN_ELEV_LEFT 1000
#define MAX_ELEV_RIGHT 3000
#define MIN_ELEV_RIGHT 1000

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


void elevPot (int leftPot, int rightPot, float speed = 1) {
	bool leftOnTarget = false;
	bool rightOnTarget = false;

	int leftSpeed;
	int rightSpeed;

	int leftCurr = SensorValue[elevLeft];
	int rightCurr = SensorValue[elevRight];

	while (!leftOnTarget && !rightOnTarget) {
		if ((leftCurr < leftPot && leftCurr < MAX_ELEV_LEFT) || leftCurr < MIN_ELEV_LEFT - 100) {
			leftSpeed = 127 * speed;
			leftOnTarget = false;
		}
		else if ((leftCurr > leftPot && leftCurr > MIN_ELEV_LEFT) || leftCurr > MAX_ELEV_LEFT + 100) {
			leftSpeed = -127 * speed;
			leftOnTarget = false;
		}
		else {
			leftSpeed = 0;
			leftOnTarget = true;
		}

		if ((rightCurr < rightPot && rightCurr < MAX_ELEV_RIGHT) || rightCurr < MIN_ELEV_RIGHT - 100) {
			rightSpeed = 127 * speed;
			rightOnTarget = false;
		}
		else if ((rightCurr > rightPot && rightCurr > MIN_ELEV_RIGHT) || rightCurr > MAX_ELEV_RIGHT + 100) {
			rightSpeed = -127 * speed;
			rightOnTarget = false;
		}
		else {
			rightSpeed = 0;
			rightOnTarget = true;
		}

		setElevSpeeds (leftSpeed, rightSpeed);
	}
}

void elevLiftMax (float speed = 1) {
	elevPot (MAX_ELEV_LEFT, MAX_ELEV_RIGHT, speed);
}

void elevLiftMin (float speed = 1) {
	elevPot (MIN_ELEV_LEFT, MIN_ELEV_RIGHT, speed);
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
