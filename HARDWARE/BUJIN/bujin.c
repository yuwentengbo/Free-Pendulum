#include "bujin.h"
#include "delay.h"
#include "mpu6050.h"

void bujin_init()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	
}

void Moter_Stop()
{
	PCout(6) = 0; PCout(7) = 0; PCout(8) = 0; PCout(9) = 0;
}

void Moter_Go(u8 speed,u8 flag,u8 x)			//1ÏòÏÂ
{
	if(flag == 0)
	{
		PCout(6) = 1; PCout(7) = 0; PCout(8) = 1; PCout(9) = 0;
		delay_ms(speed);
		
		PCout(6) = 0; PCout(7) = 1; PCout(8) = 1;  PCout(9)= 0;
		delay_ms(speed);
		
		PCout(6) = 0; PCout(7) = 1;  PCout(8) = 0; PCout(9) = 1;
		delay_ms(speed);
		
		PCout(6) = 1; PCout(7) = 0;  PCout(8)= 0;  PCout(9) = 1;
		delay_ms(speed);
	}
	else
	{
		if(x == 0)
		{
			PCout(6) = 1; PCout(7) = 0;  PCout(8)= 0;  PCout(9) = 1;
			delay_ms(speed);
			
			PCout(6) = 0; PCout(7) = 1;  PCout(8) = 0; PCout(9) = 1;
			delay_ms(speed);
		}
		else
		{
			PCout(6) = 0; PCout(7) = 1; PCout(8) = 1;  PCout(9)= 0;
			delay_ms(speed);
			
			PCout(6) = 1; PCout(7) = 0; PCout(8) = 1; PCout(9) = 0;
			delay_ms(speed);
		}
	}
}


