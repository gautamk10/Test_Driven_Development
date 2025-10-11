
#include "stm32f429xx.h"
#include "fpu.h"
#include "uart.h"
#include <stdio.h>

#define GPIOGEN			(1U<<6)
#define PIN_G_13		(1U<<13)
#define LED_GREEN	   	PIN_G_13
#define PIN_G_14		(1U<<14)
#define LED_RED         PIN_G_14


int main()
{
	//Enable FPU
	fpu_enable();

	//Initialize UART
	debug_uart_init();

	while(1)
	{
		printf("Hello From STM32\n\r");
		for(int i =0;i <9000;i++){

		}
	}

}
