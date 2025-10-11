
#include "stm32f429xx.h"
#include "fpu.h"
#include "uart.h"
#include <stdio.h>
#include <timbase.h>
#include "bsp.h"


#define VECT_TAB_BASE_ADDRESS 		FLASH_BASE
#define VECT_TAB_OFFSET				0xC000

bool btn_state;
int main()
{
	//Enable FPU
	fpu_enable();

	//Initialize UART
	debug_uart_init();

	//Initialize the Timebase
	timbase_init();

	//Initilize LED
	led_init();

	//Initilalize Push Button
	button_init();


	while(1)
	{
		led_on_green();
		led_on_red();
		printf(" Factory Application is running..\n\r");
		delay(500);
	}

}

void SystemInit(void)
{
	SCB->VTOR = VECT_TAB_BASE_ADDRESS | VECT_TAB_OFFSET ;
}
