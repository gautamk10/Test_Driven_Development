#include <string.h>
#include "unity.h"
#include "fake_stm32f429xx.h"
#include "led_pg13.h"

#ifndef BIT
#define BIT(n) (1U << (n)) // Helper for bit addertion

#endif

void setup(void){

	memset(&RCC_,0, sizeof(RCC_));
	memset(&GPIOG_,0, sizeof(GPIOG_));

}

void teardown(void){

}

void test_led_init_enables_gpiog_and_configures_pg13_output_start_off(void){
	led_init();
	TEST_ASSERT_BIT_HIGH(6,RCC->AHB1ENR);

	const uint32_t moder_mask = (0x3U << (13u * 2)); /* MODER[27:26]*/
	const uint32_t moder_out = (0x1 << (13u * 2));  /* 01b output */

	TEST_ASSERT_BITS(moder_mask, moder_out, GPIOG->MODER);

	const uint32_t pupd_mask = (0x3U << (13u * 2));
	const uint32_t pupd_none = (0x0u);

	TEST_ASSERT_BITS(pupd_mask, pupd_none, GPIOG->PUPDR);


}
