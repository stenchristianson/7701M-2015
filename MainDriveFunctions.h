//Definitions
#define TICKS_PER_INCH 100
#define TICKS_PER_TILE (TICKS_PER_INCH * 24)
#define TICKS_PER_DEG  10

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
	if      (left >= 1 && right >= 1) setDriveSpeeds ( 127,  127,  127,  127, time);
	else if (left >= 1 && right == 0) setDriveSpeeds ( 127,  0,    127,  0,   time);
	else if (left >= 1 && right <= 1) setDriveSpeeds ( 127, -127,  127, -127, time);
	else if (left == 0 && right >= 1) setDriveSpeeds ( 0,    127,  0,    127, time);
	else if (left == 0 && right == 0) setDriveSpeeds ( 0,    0,    0,    0,   time);
	else if (left == 0 && right <= 0) setDriveSpeeds ( 0,   -127,  0,   -127, time);
	else if (left <= 1 && right >= 1) setDriveSpeeds (-127,  127, -127,  127, time);
	else if (left <= 1 && right == 0) setDriveSpeeds (-127,  0,   -127,  0,   time);
	else if (left <= 1 && right <= 1) setDriveSpeeds (-127, -127, -127, -127, time);
}

void driveDistanceTick (int leftTick, int rightTick, int tol = 50, float speed = 1) {
	nMotorEncoder[driveLeftRear] = 0;
	nMotorEncoder[driveRightRear] = 0;

	bool leftOnTarget;
	bool rightOnTarget;

	while (!leftOnTarget && !rightOnTarget) {
		//Initialize motor encoder
		int leftDist = nMotorEncoder[driveLeftFront];
		int rightDist = nMotorEncoder[driveRightFront];

		//Variables to expedite setting the motor speeds
		int leftSpeed;
		int rightSpeed;

		while (!leftOnTarget && !rightOnTarget) {
			//'Alias' variables
			leftSpeed = nMotorEncoder[driveLeftFront];
			rightSpeed = nMotorEncoder[driveRightFront];

			//Check left side
			if (leftDist - tol > leftTick) {
				leftSpeed = -127;
				leftOnTarget = false;
			}
			else if (leftDist + tol < leftTick) {
				leftSpeed = 127;
				leftOnTarget = false;
			}
			else {
				leftSpeed = 0;
				leftOnTarget = true;
			}

			//Check right side
			if (rightDist - tol > rightTick) {
				rightSpeed = -127;
				rightOnTarget = false;
			}
			else if (rightDist + tol < rightTick) {
				rightSpeed = 127;
				rightOnTarget = false;
			}
			else {
				rightSpeed = 0;
				rightOnTarget = true;
			}

			//Set the drive speeds
			setDriveSpeeds (leftSpeed, rightSpeed, leftSpeed, rightSpeed);

			//Loop breaks when they both reach the target
		}
	}
}

void driveDistanceInch (float leftInch, float rightInch, int tol = 50, float speed = 1) {
	int leftTick = leftInch * TICKS_PER_INCH;
	int rightTick = rightInch * TICKS_PER_INCH;
	driveDistanceTick (leftTick, rightTick, tol, speed);
}

void driveDistanceTile (float tiles, int tol = 50, float speed = 1) {
	int ticks = tiles * TICKS_PER_TILE;
	driveDistanceTick (ticks, ticks, tol, speed);
}

void rotateTick (int ticks, signed int direction, int tol = 50, float speed = 1) {
	int leftTick = ticks * direction;
	int rightTick = ticks * direction * -1;
	driveDistanceTick (leftTick, rightTick, tol, speed);
}

void rotateDeg (int deg, signed int direction, int tol = 50, float speed = 1) {
	int ticks = deg * TICKS_PER_DEG;
	rotateTick (ticks, direction, tol, speed);
}
