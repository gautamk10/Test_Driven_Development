
#include "stm32f429xx.h"

#define GPIOGEN			(1U<<6)
#define PIN_G_13		(1U<<13)
#define LED_GREEN	   	PIN_G_13
#define PIN_G_14		(1U<<14)
#define LED_RED         PIN_G_14


int main(void)
{
	/*  Enable clock access to GPIOG*/
	RCC->AHB1ENR |= GPIOGEN;

	/* SET PG13 to output mode*/
	GPIOG->MODER |= (1U<<26);
	GPIOG->MODER &= ~(0U<<27);

	GPIOG->MODER |= (1U<<28);
	GPIOG->MODER &= ~(0U<<29);

	while(1)
	{
		GPIOG->ODR ^= LED_GREEN;
		for(int i = 0;i<100000;i++){}
		GPIOG->ODR ^= LED_RED;
	}

}
