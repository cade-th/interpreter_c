#include "interpreter_tests/include/interpreter_test.h"
#include "interpreter_tests/include/lexer_tests.h"
#include "stdio.h"

int main(void) {
    // test_interpreter();    
    LEX_TEST_RESULT result = lexer_basic_test();
    if (result.is_ok) {
        printf("Lexer Test: Success\n");
    }
    switch (UNWRAP_ERR(result)) {
            printf("Lexer Test: Fail\n");
            case NUM_TOKENS : {
                printf("Incorrect number of tokens\n");
                return 1;
            }
            case INCORRECT_TOKEN: {
                printf("Incorrect token somewhere\n");
                return 1;
            }
            case LEXER_ERROR: {
                return 1;
            }
        };
    return 0;
}

