#include "interpreter_tests/include/interpreter_test.h"
#include "interpreter_tests/include/lexer_tests.h"
#include "stdio.h"

int main(void) {
    // test_interpreter();    
    LEX_TEST_RESULT result = lexer_basic_test();
    if (result.is_ok) {
        printf("Success\n");
    }
    else {
        printf("Failure: %s\n", result.inner.err);
    }
    return 0;
}

