/*
 * sensorbase.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: Avi Weiss
 */

#ifndef SENSORBASE_CPP_
#define SENSORBASE_CPP_

class SensorBase
{

private:

public:
	SensorBase();
	bool checkPWMPort(int port);
	bool checkAnalogPort(int port);
	bool checkDigitalPort(int port);
	bool checkI2CPort(int port);
};
SensorBase::SensorBase()
{

}
bool SensorBase::checkPWMPort(int port)
{
	if(port >= 1 && port <= 10 )
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool SensorBase::checkAnalogPort(int port)
{
	if(port >= 1 && port <= 8 )
		{
			return true;
		}
		else
		{
			return false;
		}
}
bool SensorBase::checkDigitalPort(int port)
{
	if(port >= 1 && port <= 12 )
		{
			return true;
		}
		else
		{
			return false;
		}
}
bool SensorBase::checkI2CPort(int port)
{
	if(port >= 1 && port <= 8 )
		{
			return true;
		}
		else
		{
			return false;
		}
}
#endif /* SENSORBASE_CPP_ */
