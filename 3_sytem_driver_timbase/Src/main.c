
#include "stm32f429xx.h"
#include "fpu.h"
#include "uart.h"
#include <stdio.h>
#include <timbase.h>


int main()
{
	//Enable FPU
	fpu_enable();

	//Initialize UART
	debug_uart_init();

	//Initialize the Timebase
	timbase_init();


	while(1)
	{
		printf("Hello From STM32\n\r");
		delay(1);
	}

}
