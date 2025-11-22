
#include "stm32f429xx.h"
#include "fpu.h"
#include "uart.h"
#include <stdio.h>
#include <timbase.h>
#include "bsp.h"
#include "adc.h"


bool btn_state;
uint32_t sensor_value;

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

	//Initialize the ADC
	pa1_adc_init();

	/* Start ADC Conversion*/


	while(1)
	{

		btn_state = get_btn_state();
		led_on_green();
		led_on_red();
		delay(1);
		led_off_green();
		led_off_red();
		delay(1);

		sensor_value = adc_read();

	}
}
