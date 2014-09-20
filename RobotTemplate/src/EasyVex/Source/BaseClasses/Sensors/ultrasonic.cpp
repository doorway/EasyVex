/*
 * ultrasonic.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: Avi Weiss
 */

#ifndef ULTRASONIC_CPP_
#define ULTRASONIC_CPP_
#include "sensorbase.cpp"
class Ultrasonic : public SensorBase{

private:
	Gyro gyro;

public:

	int sensorport = 0;
	int curval = 0;
	int multipier;
	Ultrasonic(int SensorPort);
	int getAngle();
	void setMultiplier(int multi);
	void reset();
	void pollSensor();


};

Ultrasonic::Ultrasonic(int SensorPort)
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

int Ultrasonic::getAngle()
{
	pollSensor();
	if(sensorport == 13)
		return 0;
	else
		return curval;
}
void Ultrasonic::reset()
{
	if(sensorport != 13)
		gyroReset(gyro);
}
void Ultrasonic::setMultiplier(int multi)
{
	if(sensorport != 13) {
		gyro = gyroInit(sensorport, multi);
		reset();
		pollSensor();
	}
}
void Ultrasonic::pollSensor()
{
	if(sensorport != 13)
		curval = gyroGet(gyro);
}



#endif /* ULTRASONIC_CPP_ */
