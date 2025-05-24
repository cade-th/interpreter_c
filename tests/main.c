#include "interpreter_tests/include/interpreter_test.h"
#include "interpreter_tests/include/lexer_tests.h"
#include "stdio.h"

int main(void) {
    // test_interpreter();    
    lexer_basic_test();
    printf("Test ran\n");
    return 0;
}

