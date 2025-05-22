#include "unity.h"
#include "interpreter_tests/interpreter_test.h"

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
    RUN_TEST(
        test_interpreter
    );
    return UNITY_END();
}

