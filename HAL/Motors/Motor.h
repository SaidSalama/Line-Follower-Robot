/*
 * Motor.h
 *
 * Created: 19/10/2024 22:07:41
 *  Author: saids
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include "GPIO_NEW.h"
/*IO of motors*/
/*Right motor is connected to OC0 pin and Left motor is connected to OC2 pin*/
#define Right_Motor_Port		PORT_B
#define Left_Motor_Port		    PORT_D		
#define Right_Motor_Pin			PIN_3						//pin 3 of PORTB is OC0
#define Left_Motor_Pin			PIN_7						//pin 7 of PORTD is OC2

/*Motors Label*/
#define Right_Motor    'R'
#define Left_Motor     'L'

/*Motor Speed*/
/*The speed of the motors depends on the voltage applied to them*/
#define MAX_SPEED		255
#define MID_SPEED		255/2
#define ZERO			0

#define Motor_Speed   MAX_SPEED						//This the the configuration to be used in the functions you can change it

/*Functions Declarations*/
void Motor_Init(unsigned char Motor);
void Motor_Forward(unsigned char Motor);
void Motor_Stop(unsigned char Motor);
void Motor_Set_Speed(unsigned char Motor);

#endif /* MOTOR_H_ */