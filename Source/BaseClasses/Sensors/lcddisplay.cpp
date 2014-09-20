
#ifndef LCDSENSOR_CPP_
#define LCDSENSOR_CPP_

#include "sensorbase.cpp"
class LCDDisplay : public SensorBase{
private:

	int sensorport;
	
public:
	int Top = 1;
	int Bottom = 2;
	char TopLine[16];
	char BottomLine[16];
	LCDDisplay(int port);
	void clear();
	void println(int line, char startcol, char * string);
	void updateLCD();
	
};

LCDDisplay::LCDDisplay(int port)
{
	sensorport = port;
}
void LCDDisplay::clear()
{
	for(int i = 0; i < 16; i++)
	{
		TopLine[i]  = ' ';
		BottomLine[i]  = ' ';
	}
	updateLCD();
}
void LCDDisplay::println(int line, char startcol, char * string)
{
	for(int i = startcol; i < 16; i++)
	{
		if(line == 1)
		{
			TopLine[i]  = string[i];
		}
		else
		{
			BottomLine[i]  = string[i];
		}
	}
}
void LCDDisplay::updateLCD()
{
}