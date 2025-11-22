#include "stm32f429xx.h"
#include "fpu.h"

void fpu_enable(void)
{
	//Enable the Floating Point Unit: CP10 and CP11 of CPACR are set to full access mode
	SCB->CPACR |= (1U<<20);
	SCB->CPACR |= (1U<<21);
	SCB->CPACR |= (1U<<22);
	SCB->CPACR |= (1U<<23);


}
