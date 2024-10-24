/*
 * main.c
 *
 * Created: 10/19/2024 7:06:26 PM
 *  Author: saids
 */ 


#include "Robot.h"
#include "IR Sensor.h"

unsigned char Reading_Left;
unsigned char Reading_Right;

int main(void)
{
	
	//Initialize_The_Robot();
	Robot_init();
	
	while (1)
	{
		Reading_Right=IR_Sensor_Read(Right_IR_Sensor);
		Reading_Left=IR_Sensor_Read(Left_IR_Sensor);
		/*if the line detected on both sides it means a horizontal line so robot stops*/
		if((Reading_Left==Line_Detected)&&(Reading_Right==Line_Detected))					//Stop Condition		
		{
			Robot_Stop();
		}
		/*when the line is detected on the right so robot has to turn right to follow the line*/
		else if((Reading_Left==Line_Not_Detected)&&(Reading_Right==Line_Detected))
		{
			Robot_Turn_Right();
		}
		/*when the line is detected on the left so robot has to turn left to follow the line*/
		else if((Reading_Left==Line_Detected)&&(Reading_Right==Line_Not_Detected))
		{
			Robot_Turn_Left();
		}
		/*when the line is  not detected on the right neither on the left it means the robot is on line and has to go forward*/
		else if((Reading_Left==Line_Not_Detected)&&(Reading_Right==Line_Not_Detected))
		{
			Robot_Forward();
		}
		
		
	}
}