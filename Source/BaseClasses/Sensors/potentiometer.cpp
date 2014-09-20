/*
 * potentiometer.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: Avi Weiss
 */

#ifndef POTENTIOMETER_CPP_
#define POTENTIOMETER_CPP_

#include "sensorbase.cpp"
class Potentiometer : public SensorBase{

private:


public:

	int sensorport = 0;
	int curval = 0;
	Potentiometer(int SensorPort);
	int getValue();
	void calibrate();
	void reset();
	void pollSensor();


};

Potentiometer::Potentiometer(int SensorPort)
{

	if(checkAnalogPort(SensorPort)) {
		sensorport = SensorPort;
		analogCalibrate(SensorPort); }
	else
		sensorport = 13;
	curval = 0;
}

int Potentiometer::getValue()
{
	pollSensor();
	if(sensorport == 13)
		return 0;
	else
		return curval;
}
void Potentiometer::reset()
{
	if(sensorport != 13)
		curval = 0;
}
void Potentiometer::calibrate()
{
	if(sensorport != 13)
		analogCalibrate(sensorport);
}
void Potentiometer::pollSensor()
{
	if(sensorport != 13)
		curval = analogReadCalibrated(sensorport);
}


#endif /* POTENTIOMETER_CPP_ */
