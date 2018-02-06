#pragma config(Sensor, dgtl2,  quadA,          sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  quadB,          sensorQuadEncoder)
#pragma config(Motor,  port2,           motorA,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           motorB,        tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	// PARAMETERS //
	int kD = 0;
	int kAB = 0;

	// Initializing variables //
	int prevError = 0;

	// Zeroing sensor values //
	SensorValue[quadA] = 0;
	SensorValue[quadB] = 0;

	while(true)
	{
		int errorAB = SensorValue[quadA] - SensorValue[quadB];
		int derivativeAB = errorAB - prevErrorAB;
		prevErrorAB = errorAB;

		if(VexRT[Btn6U] == 1)
		{
			motor[motorA] = 127 - errorAB*kAB - derivativeAB*kD;
			motor[motorB] = 127 + errorAB*kAB + derivativeAB*kD;
		}

		wait1Msec(15);
	}
}
