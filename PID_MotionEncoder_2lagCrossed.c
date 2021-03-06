#pragma config(Sensor, dgtl2,  quadA,          sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  quadB,          sensorQuadEncoder)
#pragma config(Motor,  port2,           motorA,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           motorB,        tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	// PARAMETERS //
	int kP = 0;
	int kI = 0;
	int kD = 0;
	int kAB = 0;

	// Initializing variables //
	int integralA = 0;
	int prevErrorA = 0;
	int integralB = 0;
	int prevErrorB = 0;
	int CorrectionCounter = 0;

	// Zeroing sensor values //
	SensorValue[quadA] = 0;
	SensorValue[quadB] = 0;

	while(true)
	{

		if (vexRT[Btn6U] == 1)
		{
			CorrectionCounter += 1;
		}

		else if (vexRT[Btn6D] == 1)
		{
			CorrectionCounter -= 1;
		}

		else
		{
			CorrectionCounter = CorrectionCounter;
		}

		int errorA = CorrectionCounter - SensorValue[quadA];
		int errorB = CorrectionCounter - SensorValue[quadB];
		int errorAB = SensorValue[quadA] - SensorValue[quadB];

		integralA += errorA;
		integralB += errorB;

		int derivativeA = errorA - prevErrorA;
		int derivativeB = errorB - prevErrorB;

		prevErrorA = errorA;
		prevErrorB = errorB;

		motor[motorA] = errorA*kP + integralA*kI + derivativeA*kD - errorAB*kAB;
		motor[motorB] = errorB*kP + integralB*kI + derivativeB*kD + errorAB*kAB;
		wait1Msec(15);
	}
}
