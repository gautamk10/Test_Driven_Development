#include "bsp.h"

#include "stm32f429xx.h"


#define GPIOGEN			(1U<<6)

#define PIN_G13			(1U<<13)
#define LED_GREEN	   	PIN_G13

#define PIN_G14			(1U<<14)
#define LED_RED		   	PIN_G14

#define GPIOAEN			(1U<<0)
#define PIN_A0			(1U<<0)
#define BTN_PIN 		PIN_A0


void led_init(void)
{
	/*  Enable clock access to GPIOG*/
	RCC->AHB1ENR |= GPIOGEN;

	/* SET PG13 to output mode*/
	GPIOG->MODER |= (1U<<26);
	GPIOG->MODER &= ~(0U<<27);

	/*Set PG14 as output mode */
	GPIOG->MODER |= (1U<<28);
	GPIOG->MODER &= ~(0U<<29);
}

void led_on_red(void)
{
	/* Set pG14 High */
	GPIOG->ODR |= LED_RED;
}

void led_on_green(void)
{
	/* Set PG13 High */
	GPIOG->ODR |= LED_GREEN;
}

void led_off_green(void)
{
	/* Set PG13 Low */
	GPIOG->ODR &=~LED_GREEN;
}

void led_off_red(void)
{
	/* Set PG14 Low*/
	GPIOG->ODR &=~LED_RED;
}

void button_init(void)
{
	/*Enable clock access to PortA */
	RCC->AHB1ENR |= GPIOAEN;

	/*Set PA0 as input pin*/
	GPIOA->MODER &=~(1U<<0);
	GPIOA->MODER &=~(1U<<1);

}

bool get_btn_state(void){
	/* NOTE BTN is Active Low*/
	/* Check if button is pressed*/
	if(GPIOA->IDR & BTN_PIN)
	{
		return true;
	}else{
		return false;
	}
}

