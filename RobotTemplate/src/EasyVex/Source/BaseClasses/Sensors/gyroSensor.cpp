/*
 * gyroSensor.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: Avi Weiss
 */

#ifndef GYROSENSOR_CPP_
#define GYROSENSOR_CPP_

#include "sensorbase.cpp"
class GyroSensor : public SensorBase{

private:
	Gyro gyro;

public:

	int sensorport = 0;
	int curval = 0;
	int multipier;
	GyroSensor(int SensorPort);
	GyroSensor(int SensorPort, int multi);
	int getAngle();
	void setMultiplier(int multi);
	void reset();
	void pollSensor();


};

GyroSensor::GyroSensor(int SensorPort)
{
	if(checkAnalogPort(SensorPort))
		sensorport = SensorPort;
	else
		sensorport = 13;
	if(sensorport != 13)
		gyro = gyroInit(sensorport, 0);
	curval = 0;
	multipier = 0;
}
GyroSensor::GyroSensor(int SensorPort, int multi)
{
	if(checkAnalogPort(SensorPort))
		sensorport = SensorPort;
	else
		sensorport = 13;
	if(sensorport != 13)
		gyro = gyroInit(sensorport, 0);
	curval = 0;
	multipier = 0;
}
int GyroSensor::getAngle()
{
	pollSensor();
	if(sensorport == 13)
		return 0;
	else
		return curval;
}
void GyroSensor::reset()
{
	if(sensorport != 13)
		gyroReset(gyro);
}
void GyroSensor::setMultiplier(int multi)
{
	if(sensorport != 13) {
		gyro = gyroInit(sensorport, multi);
		reset();
		pollSensor();
	}
}
void GyroSensor::pollSensor()
{
	if(sensorport != 13)
		curval = gyroGet(gyro);
}



#endif /* GYROSENSOR_CPP_ */
