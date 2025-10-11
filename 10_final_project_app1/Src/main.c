
#include "stm32f429xx.h"
#include "fpu.h"
#include "uart.h"
#include <stdio.h>
#include <timbase.h>
#include "bsp.h"


#define VECT_TAB_BASE_ADDRESS 		FLASH_BASE
#define VECT_TAB_OFFSET				0x8000

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
		printf(" Application 1 is running..\n\r");
		led_on_red();
		led_off_green();
		delay(200);
		printf(" Application 1 is running..\n\r");
		led_off_red();
		led_on_green();
		delay(200);
		printf(" Application 1 is running..\n\r");

	}

}

void SystemInit(void)
{
	SCB->VTOR = VECT_TAB_BASE_ADDRESS | VECT_TAB_OFFSET ;
}
