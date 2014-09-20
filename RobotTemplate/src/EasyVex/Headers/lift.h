
#ifndef LIFTSYSTEM_H
#define LIFTSYSTEM_H


class LiftSystem
{
public:


	LiftSystem(int leftMotorChannel, int rightMotorChannel); /* DONE */
	LiftSystem(Motor leftMotor, Motor rightMotor); /* DONE */
	
	LiftSystem(int leftFrontMotorChannel, int leftBackMotorChannel, int rightFrontMotorChannel, int rightBackMotorChannel); /* DONE */
	LiftSystem(Motor leftFrontMotor, Motor leftBackMotor, Motor rightFrontMotor, Motor rightBackMotor); /* DONE */
	
	void control(JoystickButton up, JoystickButton down, int speed = 127); /* DONE */			
	void control(bool up, bool down, int speed = 127); /* DONE */
	void setMotorOutput(float output); /* DONE */
	void setReversedMotor(int motor, bool isInverted); /* DONE */
	void setMotorEncoder(int motor, int encoderPort, bool IME); /* DONE */
	void setMotorEncoder(int motor, int encoderPort); /* DONE */


protected:
	void InitLiftSystem();
	int maxMotors = 4;
	int reversedMotors[maxMotors];
	int m_maxOutput;
	Motor m_frontLeftMotor;
	Motor m_frontRightMotor;
	Motor m_rearLeftMotor;
	Motor m_rearRightMotor;
	
private:
	int GetNumMotors()
	{
		int motors = 0;
		if (m_frontLeftMotor) motors++;
		if (m_frontRightMotor) motors++;
		if (m_rearLeftMotor) motors++;
		if (m_rearRightMotor) motors++;
		return motors;
	}
};



#endif