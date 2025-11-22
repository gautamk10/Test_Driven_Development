#include "unity.h"
#include <stdint.h>
#include <string.h>
#include <math.h>

#define DEMO_ENABLE_FAILS 	0

void setUp(void){}
void tearDown(void){}


//1. Boolean and Pointer validations
void test_bool_ptr_should_pass(void) {
	int x = 123;
	TEST_ASSERT(1);
	TEST_ASSERT_TRUE(2 == 2);
	TEST_ASSERT_FALSE(0);
	TEST_ASSERT_UNLESS(0);	//alias for asserting false
	TEST_ASSERT_NULL(NULL);
	TEST_ASSERT_NOT_NULL(&x);
	
}

#if DEMO_ENABLE_FAILS
void test_bool_ptr_should_fail(void){
	int x = 0;
	TEST_ASSERT_TRUE(0);
	TEST_ASSERT_FALSE(1);
	TEST_ASSERT_NULL(&x);
	TEST_ASSERT_NOT_NULL(NULL);
}
#endif


//2. Integer equality assertions
void test_integer_equality_should_pass(void){
	TEST_ASSERT_EQUAL(7,7);
	TEST_ASSERT_EQUAL_INT(-42, -42);

	TEST_ASSERT_EQUAL_INT8( (int8_t)-5, (int8_t)-5);
	TEST_ASSERT_EQUAL_INT16( (int16_t)-1234, (int16_t)-1234);
	TEST_ASSERT_EQUAL_INT32(-123456, -123456);

	TEST_ASSERT_EQUAL_UINT(42u, 42u);
	TEST_ASSERT_EQUAL_UINT8( (uint8_t)200, (uint8_t)200);
	TEST_ASSERT_EQUAL_UINT16( (uint16_t)65500, (uint16_t) 65500);
	TEST_ASSERT_EQUAL_UINT32( (uint32_t)0xDEADBEEF, (uint32_t)0xDEADBEEF);

}

#if DEMO_ENABLE_FAILS
void test_integer_equality_should_fail(void){
	TEST_ASSERT_EQUAL_INT(10, 11);
	TEST_ASSERT_EQUAL_UINT8( (uint8_t)1, (uint8_t)2);
}
#endif


//4. Bitmask and Bit-level assertions
void test_bitmask_and_bit_level_should_pass(void){
	uint8_t actual = 0xA0;
	TEST_ASSERT_BITS(0xF0,0xA0, actual);
	TEST_ASSERT_BITS_HIGH(0xA0, actual);
	TEST_ASSERT_BITS_LOW(0x0F, actual);
}

//5. Relational Comparisons
void test_realtional_should_pass(void)
{
	TEST_ASSERT_GREATER_THAN(10,11);
	TEST_ASSERT_LESS_THAN(10,9);
}

//7. Pointers, Strings and raw memory
void test_ptr_string_memory_should_pass(void)
{
	int x;
	int* p = &x;
	TEST_ASSERT_EQUAL_PTR(&x, p);

	TEST_ASSERT_EQUAL_STRING("embedded", "embedded");
	TEST_ASSERT_EQUAL_STRING_LEN("firmwareX","firmwareY", 8);

	uint8_t exp[4] = { 1,2,3,4};
	uint8_t act[4] = { 1,2,3,4};
	TEST_ASSERT_EQUAL_MEMORY(exp,act,sizeof exp);


}
//8. Array equality assertions
void test_array_equality_should_pass(void){
	int16_t ei[3] = {-1,2,-3};
	int16_t ai[3] = {-1,2,-3};
	TEST_ASSERT_EQUAL_INT16_ARRAY(ei, ai, 3);

}

//9.Arrays compared to a single value
struct Pair{uint8_t a,b;};

void test_each_equal_should_pass(void){

	const char* sarr[3] = {"OK","OK","OK"};
	TEST_ASSERT_EACH_EQUAL_STRING("OK", sarr,3);
}

//10. Floating Point Assertions
void test_float_should_pass(void){
	TEST_ASSERT_EQUAL_FLOAT(1.5f,1.5f);

}

//11. Flow control helpers often seen in tests
void test_flow_control_pass_message(void){
	TEST_PASS_MESSAGE("Deliberate pass using TEST_PASS_MESSAGE ");
}

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_bool_ptr_should_pass);
	RUN_TEST(test_integer_equality_should_pass);
	RUN_TEST(test_bitmask_and_bit_level_should_pass);
	RUN_TEST(test_realtional_should_pass);
	RUN_TEST(test_ptr_string_memory_should_pass);
	RUN_TEST(test_array_equality_should_pass);
	RUN_TEST(test_each_equal_should_pass);
	RUN_TEST(test_float_should_pass);
	RUN_TEST(test_flow_control_pass_message);
	return UNITY_END();
}
