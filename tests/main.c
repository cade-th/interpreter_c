#include "unity.h"
#include "interpreter_tests/include/interpreter_test.h"
#include "interpreter_tests/include/lexer_tests.h"

void setUp(void) {
    // Optional: initialize test environment
}

void tearDown(void) {
    // Optional: clean up after test
}

void test_addition(void) {
    TEST_ASSERT_EQUAL_INT(4, 2 + 2);
}


int main(void) {
    UNITY_BEGIN();
    // RUN_TEST(test_interpreter);
    RUN_TEST(lexer_basic_test);
    return UNITY_END();
}

