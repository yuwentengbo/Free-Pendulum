#include "timer.h"

void TIM3_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); 

	TIM_TimeBaseStructure.TIM_Period = arr; 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); 						 
}
u32 Tim3_Get_HignCounter(void)
{
	return TIM3->CNT;
}

void TIM3_Start()
{
	TIM3->CNT = 0;
	TIM_Cmd(TIM3,ENABLE);
}

void TIM3_Close()
{
	TIM_Cmd(TIM3,DISABLE);
}