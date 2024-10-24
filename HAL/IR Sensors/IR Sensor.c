/*
 * IR_Sensor.c
 *
 * Created: 19/10/2024 22:40:33
 *  Author: saids
 */ 

#include "IR Sensor.h"
#include "GPIO_NEW.h"

/*Functions Definitions*/
void IR_Sensor_Init(unsigned char IR_Sensor )
{
	if(IR_Sensor==Right_IR_Sensor)
		Pin_Direction(IR_Sensors_PORT,Input,Right_IR_Sensor_Pin);
	else if (IR_Sensor==Left_IR_Sensor)
		Pin_Direction(IR_Sensors_PORT,Input,Left_IR_Sensor_Pin);
}
unsigned char IR_Sensor_Read(unsigned char IR_Sensor)
{
	if(IR_Sensor==Right_IR_Sensor)
		return	Pin_Read(IR_Sensors_PORT,Right_IR_Sensor_Pin);
	else if (IR_Sensor==Left_IR_Sensor)
		return	Pin_Read(IR_Sensors_PORT,Left_IR_Sensor_Pin);
}