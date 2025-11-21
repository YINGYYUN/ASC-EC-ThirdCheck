#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "Delay.h"

#include "Car.h"

void Go_Ahead(void)
{
	Motor_SetPWM1(Standard_Speed);
	Motor_SetPWM2(Standard_Speed);
}
void Go_Back(void)
{
	Motor_SetPWM1(-Standard_Speed);
	Motor_SetPWM2(-Standard_Speed);
}
void Turn_Left(void)
{
	Motor_SetPWM1(0);
	Motor_SetPWM2(Standard_Speed);
}
void Turn_Right(void)
{
	Motor_SetPWM1(Standard_Speed);
	Motor_SetPWM2(0);
	
}
void Self_Left(void)
{
	Motor_SetPWM1(-Standard_Speed);
	Motor_SetPWM2(Standard_Speed);
}
void Self_Right(void)
{
	Motor_SetPWM1(Standard_Speed);
	Motor_SetPWM2(-Standard_Speed);
}
void Car_Stop(void)
{
	Motor_SetPWM1(0);
	Motor_SetPWM2(0);
}
