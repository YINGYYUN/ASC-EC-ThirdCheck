#include "stm32f10x.h"  // Device header
#include "Delay.h"
#include "OLED.h"
#include "LED.h"
#include "Key.h"
#include "Timer.h"


uint8_t KeyNum;
uint8_t LED1Mode;
uint8_t LED2Mode;

uint16_t i;

int main(void)
{	
	OLED_Init();
	LED_Init();
	Key_Init();
	Timer_Init();
	
	OLED_ShowString(1,1,"i:");
	OLED_ShowString(2,1,"LED1Mode:");
	OLED_ShowString(3,1,"LED2Mode:");
	
	while(1)
	{
		KeyNum = Key_GetNum();
		
		if (KeyNum == 1)
		{
			LED1Mode ++ ;
			LED1Mode %= 5 ;
			LED1_SetMode(LED1Mode);
		}
		if (KeyNum == 2)
		{
			LED2Mode ++ ;
			LED2Mode %= 5 ;
			LED2_SetMode(LED1Mode);
		}
		
		OLED_ShowNum(1, 3, i++, 5);
		OLED_ShowNum(2, 10, LED1Mode, 1);
		OLED_ShowNum(3, 10, LED2Mode, 1);

	}
		
}

void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2,TIM_IT_Update) == SET )
	{
		//由定时器中断自动执行;有利于多模块共用定时器定时
		//同时，需要防止中断重叠
		//一:减小模块内中断函数的内容，减小运行时间
		//二：增加定时器的基础时间
		Key_Tick();
		LED_Tick();
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}
