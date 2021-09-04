
#include "led.h"
#include "stm32f10x.h"
#include "stdio.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;    //GPIO��ʼ���ṹ
	POWER_G_IO_RCC_ENABLE();
	// POWER_R_IO_RCC_ENABLE();

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//�������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = POWER_G_IO_PIN;
	GPIO_Init(POWER_G_IO_PORT, &GPIO_InitStructure);                        //��ʼ�� IO
	
	// GPIO_InitStructure.GPIO_Pin = POWER_R_IO_PIN;
	// GPIO_Init(POWER_R_IO_PORT, &GPIO_InitStructure);                        //��ʼ�� IO
	LED_PowerG();
}

void leds_init(char led_n)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	switch(led_n){
		case 0:
			LED0_RCC_ENABLE();
			GPIO_InitStructure.GPIO_Pin = LED0_PIN;
			GPIO_Init(LED0_PORT, &GPIO_InitStructure);
			LED0_POWER_OFF();
			break;
		case 1:
			LED1_RCC_ENABLE();
			GPIO_InitStructure.GPIO_Pin = LED1_PIN;
			GPIO_Init(LED1_PORT, &GPIO_InitStructure);
			LED1_POWER_OFF();
			break;
		case 2:
			LED2_RCC_ENABLE();
			GPIO_InitStructure.GPIO_Pin = LED2_PIN;
			GPIO_Init(LED2_PORT, &GPIO_InitStructure);
			LED2_POWER_OFF();
			break;
		default:
			printf("error input led_n\r\n");
			break;
	}
}

void led_set_status(char led_n,char status)
{
	switch (led_n)
	{
		case 0:
			if(status)
				LED0_POWER_ON();
			else
				LED0_POWER_OFF();
		case 1:
			if(status)
				LED1_POWER_ON();
			else
				LED1_POWER_OFF();
			break;
		case 2:
			if(status)
				LED2_POWER_ON();
			else
				LED2_POWER_OFF();
			break;
		default:
			break;
	}
}
