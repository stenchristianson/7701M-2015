#pragma config(Sensor, in1,    elevLeft,       sensorPotentiometer)
#pragma config(Sensor, in2,    elevRight,      sensorPotentiometer)
#pragma config(Sensor, dgtl1,  driveLeft,      sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  driveRight,     sensorQuadEncoder)
#pragma config(Motor,  port1,           flyLeft,       tmotorVex393HighSpeed, openLoop)
#pragma config(Motor,  port2,           elevLeft,      tmotorVex393, openLoop)
#pragma config(Motor,  port3,           elevRight,     tmotorVex393, openLoop)
#pragma config(Motor,  port4,           driveLeftFront, tmotorVex393HighSpeed, openLoop, encoder, encoderPort, dgtl1, 1000)
#pragma config(Motor,  port5,           driveRightFront, tmotorVex393HighSpeed, openLoop, encoder, encoderPort, dgtl3, 1000)
#pragma config(Motor,  port6,           driveLeftRear, tmotorVex393HighSpeed, openLoop, encoder, encoderPort, dgtl1, 1000)
#pragma config(Motor,  port7,           driveRightRear, tmotorVex393HighSpeed, openLoop, encoder, encoderPort, dgtl3, 1000)
#pragma config(Motor,  port8,           convLeft,      tmotorVex393, openLoop)
#pragma config(Motor,  port9,           convRight,     tmotorVex393, openLoop)
#pragma config(Motor,  port10,          flyRight,      tmotorVex393HighSpeed, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

//Includes
#include "Vex_Competition_Includes.c"
#include <MainDriveFunctions.h>


void pre_auton () {

}

task autonomous () {

}

task usercontrol () {

}
