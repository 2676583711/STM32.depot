#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
void delay(int t)
{
     int i;
     for( ;t>0; t--)
         for(i=0;i<1000;i++);
}

int main()
{
     GPIO_InitTypeDef GPIOE_6_mode;
     RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOE, ENABLE );    
     GPIOE_6_mode.GPIO_Pin = GPIO_Pin_6;
     GPIOE_6_mode.GPIO_Speed = GPIO_Speed_50MHz;
     GPIOE_6_mode.GPIO_Mode = GPIO_Mode_Out_PP;
     GPIO_Init(GPIOE, &GPIOE_6_mode);    
     while(1)
     {
         GPIO_ResetBits( GPIOE, GPIO_Pin_6);  
         delay(1000);
			 
         GPIO_SetBits( GPIOE, GPIO_Pin_6);     
         delay(5000);
     }
}