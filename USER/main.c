#include "key.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "bujin.h"
#include "encoder.h"
#include  "1602.h"

/**
	 按键PC5,PA15
	 步进电机：PC6,7,8,9
	 旋转编码器	PC0,1
	 1602 PA0^7	PC2,3,4
**/

void tar1();
void tar2();
float encoder_angle = 0;
void System_init()
{
	NVIC_Configuration();
	delay_init();
	uart_init(9600);
	KEY_Init();
	encoder_init();
	lcd1602_init();
	bujin_init();	 
}

 int main(void)
 {	
	u8 flag = 0, key_value = 0;
	float angle=0;
	System_init();
	
	while(key_value == 0)
	{
		key_value = KEY_Scan(0);
		delay_ms(10);
	}
	switch(key_value)
	{
		case KEY0_PRES:		 tar1();	break;
		case KEY1_PRES:		 tar2();	break;		
	}
	
	return 0;
 }

//第一问	  
void tar1()
{
	u8 i;
	float angle;
	while(1)
	{
		angle=encoder_get_angle();
		if(angle>45&&angle<60)
		{
			if((angle-encoder_angle)<-1)
			{
				for(i=0;i<50;i++)
				{
					Moter_Go(10,0,0);
				}
				break;
			}
		}
		else
		{
			encoder_angle = angle;
		}
	}
	
}

//第二问
void tar2()
{
	u8 flag = 0, key_value = 0;
	float angle=0;
	while(1)
	{
		angle=encoder_get_angle();
		if(angle>45&&angle<60)
		{
			if((angle-encoder_angle)<-1)
			{
				for(key_value=0;key_value<encoder_angle/7.2;key_value++)
				{
					Moter_Go(6,0,0);
				}
				break;
			}
			else if((angle-encoder_angle)>3.6)
			{
				Moter_Go(9,1,flag);
				encoder_angle=angle;
				flag = (flag+1)%2;
				lcd1602_show(encoder_angle);
			}
		}
		
		else if((angle-encoder_angle)>3.6)
		{
			Moter_Go(9,1,flag);
			encoder_angle=angle;
			flag = (flag+1)%2;
			lcd1602_show(encoder_angle);
		}

	}
}




