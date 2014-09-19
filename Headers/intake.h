
#ifndef LIFTSYSTEM_H
#define LIFTSYSTEM_H


class Intake
{
public:


	Intake(int leftMotorChannel, int rightMotorChannel); /* DONE */
	Intake(Motor leftMotor, Motor rightMotor); /* DONE */
	
	
	void controlIntake(JoystickButton up, JoystickButton down, int speed = 127); /* DONE */			
	void control(bool up, bool down, int speed = 127); /* DONE */
	void setMotorOutput(float output); /* DONE */
	void setReversedMotor(int motor, bool isInverted); /* DONE */
	void setMotorEncoder(int motor, int encoderPort, bool IME); /* DONE */
	void setMotorEncoder(int motor, int encoderPort); /* DONE */


protected:
	void InitIntake();
	int maxMotors = 2;
	int reversedMotors[maxMotors];
	int m_maxOutput;
	Motor m_LeftMotor;
	Motor m_RightMotor;
	
private:
	int GetNumMotors()
	{
		int motors = 0;
		if (m_LeftMotor) motors++;
		if (m_RightMotor) motors++;
		return motors;
	}
};



#endif