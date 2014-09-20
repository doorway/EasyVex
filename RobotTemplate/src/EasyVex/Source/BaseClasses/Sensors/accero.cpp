/*
 * accSensor.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: Avi Weiss
 */

#ifndef ACCSENSOR_CPP_
#define ACCSENSOR_CPP_

#include "sensorbase.cpp"
class Accelerometer : public SensorBase{

private:
	int sensorport = 0;
	int curval = 0;
	int multipier;
public:

	Accelerometer(int SensorPort);
	int getAcceleration();
	void setCalibrate();
	void reset();
	void pollSensor();


};

Accelerometer::Accelerometer(int SensorPort)
{
	if(checkAnalogPort(SensorPort))
		sensorport = SensorPort;
	else
		sensorport = 13;
	if(sensorport != 13)
		analogCalibrate(sensorport);
	curval = 0;
	multipier = 0;
}
int Accelerometer::getAcceleration()
{
	pollSensor();
	if(sensorport == 13)
		return 0;
	else
		return curval;
}
void Accelerometer::reset()
{
	if(sensorport != 13)
		gyroReset(gyro);
}
void Accelerometer::setMultiplier(int multi)
{
	if(sensorport != 13) {
		analogCalibrate(sensorport);
		reset();
		pollSensor();
	}
}
void Accelerometer::pollSensor()
{
	if(sensorport != 13)
		curval = analogReadCalibratedHR(sensorport);
}



#endif /* GYROSENSOR_CPP_ */
