
#include "stm32f429xx.h"

#include "uart.h"
#include <stdio.h>

#include <stdbool.h>

#define GPIOGEN			(1U<<6)
#define PIN_G13			(1U<<13)
#define LED_GREEN	   	PIN_G13

bool btn_state;

#define VECT_TAB_BASE_ADDRESS 		FLASH_BASE
#define VECT_TAB_OFFSET				0x8000

struct btl_common_apis
{
	void(*led_init)(void);
	void(*led_toggle)(uint32_t dly);
	void(*led_on)(void);
	void(*led_off)(void);
	void(*button_init)(void);
	bool(*get_btn_state)(void);
	void(*fpu_enable)(void);
	void(*debug_uart_init)(void);
	void(*timbase_init)(void);

};

int main()
{

	struct btl_common_apis *common_apis = (struct btl_common_apis*)0x0800C000;
	//Enable FPU
	common_apis->fpu_enable();

	//Initialize UART
	common_apis->debug_uart_init();

	//Initialize the Timebase
	common_apis->timbase_init();

	//Initilize LED
	common_apis->led_init();

	//Initilalize Push Button
	common_apis->button_init();


	while(1)
	{
		printf("User Application Version 2 Running\n\r");
	}

}

void SystemInit(void)
{
	SCB->VTOR = VECT_TAB_BASE_ADDRESS | VECT_TAB_OFFSET ;
}
