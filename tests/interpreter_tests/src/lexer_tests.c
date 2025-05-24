#include "../include/lexer_tests.h"
#include "../../../include/lexer.h"

LEX_TEST_RESULT lexer_basic_test(void) {
    char* input = "=+(){},;";

    int expected_tokens_size = 9;
    Token expected_tokens[] = {
        {ASSIGN, "="},
        {PLUS, "+"},
        {LET, "("},
        {LET, ")"},
        {LET, "{"},
        {LET, "}"},
        {COMMA, ","},
        {SEMICOLON, ";"},
        {Eof, ""}
    };

    Lexer lexer = Lexer_new(input);
    LEX_RESULT result = lex(&lexer);
    if (result.is_ok) {
        for (int i=0; i < expected_tokens_size; i++) {
            /* do something else here
            TEST_ASSERT(result[i].type == expected_tokens[i].type);        
            TEST_ASSERT(result[i].literal == expected_tokens[i].literal);        
            */
        }

    } else {
        LEX_TEST_RESULT error = ERR(result.inner.err);
        return error;
    }

    
}
