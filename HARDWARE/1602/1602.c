#include "1602.h"
#include "delay.h"
void lcd1602_init()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOA, ENABLE);	 
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init(GPIOC, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init(GPIOC, &GPIO_InitStructure);	
	
	LCDEN = 0;
	lcd1602_wc(0x38);
	lcd1602_wc(0x0c);
	lcd1602_wc(0x06);
	lcd1602_wc(0x01);
	
	lcd1602_wc(0x80);
}
void lcd1602_wc(u8 arr)
{
	u8 i,flag;
	LCDRS = 0;
	GPIOA->ODR=0x00ff&arr;
	delay_ms(5);
	LCDEN = 1;
	delay_ms(5);
	LCDEN = 0;
}
void lcd1602_wd(u8 data)
{
	u8 i,flag;	
	LCDRS = 1;
	GPIOA->ODR=0x00ff&data;
	delay_ms(5);
	LCDEN = 1;
	delay_ms(5);
	LCDEN = 0;
}

void lcd1602_show(float angle)
{
	int i=2,x,data = (int)angle;
	u8 a[3];
	while(data)
	{
		x=data%10;
		a[i--] = x; 
		delay_us(5);
		data=data/10;
	}
	lcd1602_wc(0x01);
	for(i=i+1;i<3;i++)
		lcd1602_wd(a[i]+48);
}
