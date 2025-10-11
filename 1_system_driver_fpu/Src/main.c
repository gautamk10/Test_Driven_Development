
#include "stm32f429xx.h"

//Enable the Generic Drivers
//FPU, UART,  GPIO, TIMBASE

#define GPIOGEN			(1U<<6)
#define PIN_G_13		(1U<<13)
#define LED_GREEN	   	PIN_G_13
#define PIN_G_14		(1U<<14)
#define LED_RED         PIN_G_14


int main(void)
{
	//Enable FPU
	fpu_enable();

	while(1)
	{

	}

}
