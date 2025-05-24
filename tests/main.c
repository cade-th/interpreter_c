// #include "interpreter_tests/include/interpreter_test.h"
#include "interpreter_tests/include/lexer_tests.h"
#include "stdio.h"

int main(void) {
    // test_interpreter();    
    LEX_TEST_RESULT result = lexer_basic_test();
    if (result.is_ok) {
        printf("Lexer Test: Success\n");
        return 0;
    }
    else {
        printf("Lexer Test: Fail\n");
        switch (UNWRAP_ERR(result)) {
            case NUM_TOKENS : {
                printf("Incorrect number of tokens\n");
                return 1;
            }
            case INCORRECT_TOKEN_LITERAL: {
                printf("Incorrect token literal somewhere\n");
                return 1;
            }
            case INCORRECT_TOKEN_TYPE: {
                printf("Incorrect token type somewhere\n");
                return 1;
            }
            case LEXER_ERROR: {
                return 1;
            }
        };
    return 1;
    }
}

