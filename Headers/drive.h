
#ifndef ROBOTDRIVE_H_
#define ROBOTDRIVE_H_


class DriveSystem
{
public:


	DriveSystem(int leftMotorChannel, int rightMotorChannel); /* DONE */
	DriveSystem(Motor leftMotor, Motor rightMotor); /* DONE */
	
	DriveSystem(int leftFrontMotorChannel, int leftBackMotorChannel, int rightFrontMotorChannel, int rightBackMotorChannel); /* DONE */
	DriveSystem(Motor leftFrontMotor, Motor leftBackMotor, Motor rightFrontMotor, Motor rightBackMotor); /* DONE */
	
				
	void Drive(float outputMagnitude, float curve); /* DONE */
	void TankDrive(JoystickAxis leftStick, JoystickAxis rightStick, bool squaredInputs = true); /* DONE */
	void TankDrive(Stick leftStick, Stick rightStick, bool squaredInputs = true); /* DONE */
	void TankDrive(float leftValue, float rightValue, bool squaredInputs = true); /* DONE */
	void ArcadeDrive(Stick arcstick, bool squaredInputs = true); /* DONE */
	void ArcadeDrive(float moveValue, float rotateValue, bool squaredInputs = true); /* DONE */
	void MecanumDrive(float x, float y, float rotation, float gyroAngle = 0.0); /* DONE */
	void HolonomicDrive(float magnitude, float direction, float rotation); /* DONE */
	void setMotorOutputs(float leftOutput, float rightOutput); /* DONE */
	void setReversedMotor(int motor, bool isInverted); /* DONE */
	void setMotorEncoder(int motor, int encoderPort, bool IME); /* DONE */
	void setMotorEncoder(int motor, int encoderPort); /* DONE */
	void enableDriveDeadband();


protected:
	void setupObject();
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

