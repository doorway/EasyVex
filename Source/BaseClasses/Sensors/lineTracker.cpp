/*
 * lineTracker.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: Avi Weiss
 */

#ifndef LINETRACKER_CPP_
#define LINETRACKER_CPP_

#include "sensorbase.cpp"
class LineTracker : public SensorBase{

private:


public:

	int sensorport = 0;
	int curval = 0;
	LineTracker(int SensorPort);
	int getLight();
	void calibrate();
	void reset();
	void pollSensor();


};

LineTracker::LineTracker(int SensorPort)
{

	if(checkAnalogPort(SensorPort)) {
		sensorport = SensorPort;
		analogCalibrate(SensorPort); }
	else
		sensorport = 13;
	curval = 0;
}

int LineTracker::getLight()
{
	pollSensor();
	if(sensorport == 13)
		return 0;
	else
		return curval;
}
void LineTracker::reset()
{
	if(sensorport != 13)
		curval = 0
}
void LineTracker::calibrate()
{
	if(sensorport != 13)
		analogCalibrate(sensorport);
}
void LineTracker::pollSensor()
{
	if(sensorport != 13)
		curval = analogReadCalibrated(sensorport);
}

class LightSensor : public SensorBase{

private:


public:

	int sensorport = 0;
	int curval = 0;
	LightSensor(int SensorPort);
	int getLight();
	void calibrate();
	void reset();
	void pollSensor();


};

LightSensor::LightSensor(int SensorPort)
{

	if(checkAnalogPort(SensorPort)) {
		sensorport = SensorPort;
		analogCalibrate(SensorPort); }
	else
		sensorport = 13;
	curval = 0;
}

int LightSensor::getLight()
{
	pollSensor();
	if(sensorport == 13)
		return 0;
	else
		return curval;
}
void LightSensor::reset()
{
	if(sensorport != 13)
		curval = 0
}
void LightSensor::calibrate()
{
	if(sensorport != 13)
		analogCalibrate(sensorport);
}
void LightSensor::pollSensor()
{
	if(sensorport != 13)
		curval = analogReadCalibrated(sensorport);
}

#endif /* LINETRACKER_CPP_ */
