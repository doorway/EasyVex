/*
 * digitalInput.cpp
 *
 *  Created on: Sep 3, 2014
 *      Author: Avi Weiss
 */

#ifndef DIGITALINPUT_CPP_
#define DIGITALINPUT_CPP_
#include "sensorbase.cpp"
class DigitalInput : public SensorBase{

private:


public:

	int sensorport = 0;
	int curval = 0;
	DigitalInput(int SensorPort);
	int isPressed();
	void pollSensor();


};

DigitalInput::DigitalInput(int SensorPort)
{
	if(checkDigitalPort(SensorPort))
		sensorport = SensorPort;
	else
		sensorport = 13;

	curval = 0;
}
int DigitalInput::isPressed()
{
	pollSensor();
	if(sensorport == 13)
		return 0;
	else
		return curval == 0 ? true : false;
}
void DigitalInput::pollSensor()
{
	if(sensorport != 13)
		curval = digitalRead(sensorport)
}




#endif /* DIGITALINPUT_CPP_ */
