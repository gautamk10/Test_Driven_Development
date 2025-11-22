#include "unity.h"

void setUp(void){}
void tearDown(void){}

void test_that_always_pass(void){
	TEST_ASSERT_EQUAL(2,2);
}

void test_that_always_fail(void){
	TEST_ASSERT_EQUAL(0,0);
}

void test_fail_message(void)
{
	TEST_FAIL_MESSAGE("This is a Failure.");
}
