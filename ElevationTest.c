#pragma config(Sensor, in1,    elevLeft,       sensorPotentiometer)
#pragma config(Sensor, in2,    elevRight,      sensorPotentiometer)
#pragma config(Motor,  port1,           elevLeft,      tmotorVex393, openLoop)
#pragma config(Motor,  port2,           elevRight,     tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main () {
	//Repeatedly prints the angle that the elevation mechanism is at while allowing joystick control

	int i = 0;

	while (true) {
		if (i % 10 == 0) {
			clearDebugStream();
			writeDebugStreamLine ("Left: %d", SensorValue[elevLeft]);
			writeDebugStreamLine ("Right: %d", SensorValue[elevRight]);
		}

		if (vexRT[Btn6U]) {
			motor[elevLeft] = 127;
			motor[elevRight] = 127;
		}
		else if (vexRT[Btn6D]) {
			motor[elevLeft] = -127;
			motor[elevRight] = 127;
		}
		else {
			motor[elevLeft] = 0;
			motor[elevRight] = 0;
		}

		wait1Msec(50);
		i++;
	}
}