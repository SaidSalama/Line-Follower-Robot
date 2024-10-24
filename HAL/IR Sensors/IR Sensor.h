/*
 * IR_Sensor.h
 *
 * Created: 19/10/2024 22:40:10
 *  Author: saids
 */ 


#ifndef IR SENSOR_H_
#define IR SENSOR_H_

#include "GPIO_NEW.h"


/*IO of sensors*/
#define IR_Sensors_PORT			PORT_C
#define Right_IR_Sensor_Pin		PIN_0
#define Left_IR_Sensor_Pin		PIN_7

/*Sensors*Label*/
#define Right_IR_Sensor			'R'
#define Left_IR_Sensor			'L'

/*Direction of line*/
#define Line_Not_Detected                  1
#define Line_Detected					   0

/*Functions declarations*/
void IR_Sensor_Init(unsigned char IR_Sensor );
unsigned char IR_Sensor_Read(unsigned char IR_Sensor);
#endif /* IR SENSOR_H_ */