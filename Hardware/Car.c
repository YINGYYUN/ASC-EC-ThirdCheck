#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "Delay.h"

#include "Car.h"

void Go_Ahead(void)
{
	Motor_SetPWM1(Standard_Speed_1);
	Motor_SetPWM2(Standard_Speed_1);
}
void Go_Back(void)
{
	Motor_SetPWM1(-Standard_Speed_1);
	Motor_SetPWM2(-Standard_Speed_1);
}
void Turn_Left(void)
{
	Motor_SetPWM1(Standard_Speed_4);
	Motor_SetPWM2(Standard_Speed_3);
}
void Turn_Right(void)
{
	Motor_SetPWM1(Standard_Speed_3);
	Motor_SetPWM2(Standard_Speed_4);
	
}
void Self_Left1(void)
{
	Motor_SetPWM1(-Standard_Speed_1);
	Motor_SetPWM2(Standard_Speed_1);
}
void Self_Right1(void)
{
	Motor_SetPWM1(Standard_Speed_1);
	Motor_SetPWM2(-Standard_Speed_1);
}
void Self_Left2(void)
{
	Motor_SetPWM1(-Standard_Speed_2);
	Motor_SetPWM2(Standard_Speed_2);
}
void Self_Right2(void)
{
	Motor_SetPWM1(Standard_Speed_2);
	Motor_SetPWM2(-Standard_Speed_2);
}


void Car_Stop(void)
{
	Motor_SetPWM1(0);
	Motor_SetPWM2(0);
}
