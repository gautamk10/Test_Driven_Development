
#include "stm32f429xx.h"
#include "fpu.h"
#include "uart.h"
#include <stdio.h>
#include <timbase.h>
#include "bsp.h"

bool btn_state;

unsigned char __attribute__((section(".custom_ram_block"))) custom_ram_buff[10];
unsigned char __attribute__((section(".custom_flash_block"))) custom_flash_buff[20];
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
		led_on();
		delay(3);
		led_off();
		btn_state = get_btn_state();


	}

}
