/*
 * Robot.c
 *
 * Created: 19/10/2024 23:11:56
 *  Author: saids
 */ 
#include "Robot.h"
#include "Motor.h"
#include "_8bit_timer.h"
#include "IR Sensor.h"

/*Functions Definitions*/
Robot_init()
{
	Motor_Init(Right_Motor);
	Motor_Init(Left_Motor);
	IR_Sensor_Init(Right_IR_Sensor);
	IR_Sensor_Init(Left_IR_Sensor_Pin);
}
void Robot_Turn_Left()					/*To turn left we stop the left motors so the movements of right motor will force the robot to turn left*/
{
	Motor_Stop(Left_Motor);
	Motor_Forward(Right_Motor);	
}
void Robot_Turn_Right()
{
	Motor_Stop(Right_Motor);
	Motor_Forward(Left_Motor);
}
void Robot_Forward()
{
	Motor_Forward(Right_Motor);
	Motor_Forward(Left_Motor);
}
void Robot_Stop()
{
	Motor_Stop(Left_Motor);
	Motor_Stop(Right_Motor);
}