#include "unity.h"
#include "led_pg13.h"
#include "fake_stm32f429xx.h"
#include <string.h>

/* Unity setup and teardown */
void setUp(void) {
    /* Reset fake hardware before each test */
    memset(&RCC_, 0, sizeof(RCC_));
    memset(&GPIOG_, 0, sizeof(GPIOG_));
}

void tearDown(void) {
    /* Nothing to do here */
}

/* Test functions declaration */
void test_led_init_enables_gpiog_and_configures_pg13_output_start_off(void);

/* Main function */
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_led_init_enables_gpiog_and_configures_pg13_output_start_off);
    return UNITY_END();
}