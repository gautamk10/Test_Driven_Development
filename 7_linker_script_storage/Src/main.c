#include "stm32f429xx.h"
#include "fpu.h"
#include "uart.h"
#include <stdio.h>
#include <timbase.h>
#include "bsp.h"


#define GPIOGEN			(1U<<6)
#define PIN_G13			(1U<<13)
#define LED_GREEN	   	PIN_G13

bool btn_state;
#define CUSTOM_FUNC __attribute__((section(".custom_section")))

unsigned char __attribute__((section(".custom_ram_block"))) custom_ram_buff[10];
unsigned char __attribute__((section(".custom_flash_block"))) custom_flash_buff[20];

void CUSTOM_FUNC led_toggle(uint32_t dly_ms)
{
	GPIOG->ODR ^= LED_GREEN;
	delay(dly_ms);
}
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
		led_toggle(500);


	}

}
