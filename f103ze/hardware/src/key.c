#include "key.h"
#include "stm32f10x.h"
#include "exti.h"

void KEY0_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure); 
}

void KEY1_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure); 
}

void KEY2_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
}

void keys_init(char key_n)
{
	switch (key_n)
	{
	case 10:
		KEY0_init();
		EXTI3_Init();
		break;
	
	case 11:
		KEY1_init();
		EXTI4_Init();
		break;

	case 12:
		KEY2_init();
		EXTI0_Init();
		break;

	default:
		break;
	}
}

char key_is_high(char key_n)
{
	char status = 1;
	return status;
}

uint8_t key_down()
{
    if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==RESET)
        return 1;
    else
        return 0;
}
