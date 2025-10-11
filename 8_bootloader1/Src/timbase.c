#include <timbase.h>
#include "stm32f429xx.h"

#define CTRL_ENABLE 		 (1U<<0)
#define CTRL_TICKINT		 (1U<<1)
#define CTRL_CLKSRC 		 (1U<<2)
#define CTRL_COUNTFLAG		 (1U<<16)

#define ONE_SEC_LOAD 	   	16000000
#define ONE_M_SEC_LOAD 	   	16000

#define TIKC_FREQ 			1

#define MAX_DELAY 			0xFFFFFFFF

volatile uint32_t g_curr_tick;
volatile uint32_t g_curr_tick_p;

/* Delay in Seconds*/
void delay(uint32_t delay)
{
	uint32_t tickstart = get_tick();
	uint32_t wait = delay;

	if(wait < MAX_DELAY){
		wait += (uint32_t)TIKC_FREQ;
	}

	while((get_tick() -  tickstart) < wait){}
}

uint32_t get_tick(void)
{
	__disable_irq();
	g_curr_tick_p = g_curr_tick;
	__enable_irq();

	return g_curr_tick_p;
}

void tick_increment(void){
	g_curr_tick += TIKC_FREQ;
}

void timbase_init(void){

	/* Disable Global Interrupts*/
	__disable_irq();

	/*Load the timer with Number of CLock cycles for one second*/
	SysTick->LOAD = ONE_M_SEC_LOAD - 1;

	/* Clear SysTick Current Value register*/
	SysTick->VAL = 0;

	/* Select internal clock source*/
	SysTick->CTRL = CTRL_CLKSRC;

	/* Enable the interrupt*/
	SysTick->CTRL |= CTRL_TICKINT;

	/* Enable SysTick*/
	SysTick->CTRL  |= CTRL_ENABLE;

	/* Enable Global Interrupts*/
	__enable_irq();

}

void SysTick_Handler(void)
{
	tick_increment();
}
