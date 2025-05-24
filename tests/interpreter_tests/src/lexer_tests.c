#include "../include/lexer_tests.h"
#include "../../../include/lexer.h"
#include <stdio.h>

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
    LEX_RESULT lex_result = lex(&lexer);
    if (lex_result.is_ok) {
            /* do something else here
        for (int i=0; i < expected_tokens_size; i++) {
            TEST_ASSERT(result[i].type == expected_tokens[i].type);        
            TEST_ASSERT(result[i].literal == expected_tokens[i].literal);        
        }
        */

    } else {
        printf("%s",UNWRAP_ERR(lex_result));
        LEX_TEST_RESULT result = ERR(LEXER_ERROR);
        return result;
    }

    
}
