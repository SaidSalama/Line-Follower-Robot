/*
 * Motor.c
 *
 * Created: 19/10/2024 22:08:01
 *  Author: saids
 */ 
#include "Motor.h"
#include "GPIO_NEW.h"
#include "_8bit_timer.h"

/*Functions Definition*/
void Motor_Init(unsigned char Motor)
{
	if(Motor==Right_Motor)
	{
		/*OC0 as output*/
		Pin_Direction(Right_Motor_Port,Output,Right_Motor_Pin);					
		/*Initialize Timer0 to generate PWM to control the motor*/
		TIM0_CLCK_Select(Clck_1);							
		TIM0_Wave_Generation_Mode(Phase_Correct_PWM_Mode);
		TIM0_Output_Compare_Mode(Clear_OC_Pin);
		
	}
	else if (Motor==Left_Motor)
	{
		/*OC2 as output*/
		Pin_Direction(Left_Motor_Port,Output,Left_Motor_Pin);
		/*Initialize Timer0 to generate PWM to control the motor*/
		TIM2_CLCK_Select(Clck_1);
		TIM2_Wave_Generation_Mode(Phase_Correct_PWM_Mode);
		TIM2_Output_Compare_Mode(Clear_OC_Pin);
	}
}
void Motor_Set_Speed(unsigned char Motor)
{
	if(Motor==Right_Motor)
	{
		TIM0_Set_Compare_Value(Motor_Speed);
	}
	else if (Motor==Left_Motor)
	{
		TIM2_Set_Compare_Value(Motor_Speed);
	}
}
void Motor_Forward(unsigned char Motor)
{
	Motor_Set_Speed( Motor);						//for the motor to move forward we have just to set its speed 
}

void Motor_Stop(unsigned char Motor)
{
	//this configuration makes the outpat comapre always zero so motors stop
	if(Motor==Right_Motor)
	{
		TIM0_Set_Compare_Value(ZERO);
	}
	else if (Motor==Left_Motor)
	{
		TIM2_Set_Compare_Value(ZERO);
	}
}