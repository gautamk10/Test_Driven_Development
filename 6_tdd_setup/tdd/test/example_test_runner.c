#include "unity.h"

//Forward Declaration of Test Functions
void test_that_always_pass(void);
void test_that_always_fail(void);
void test_fail_message(void);

int main(void)
{
	//1. begin unity
	UNITY_BEGIN();

	//2. Run Test
	RUN_TEST(test_that_always_fail);
	RUN_TEST(test_that_always_pass);
	RUN_TEST(test_fail_message);

	//3. End unity
	return UNITY_END();
}
