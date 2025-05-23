#include "../../unity.h"
#include "../include/lexer_tests.h"
#include "../../../include/lexer.h"

void lexer_basic_test(void) {
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
    Token *result = lex(&lexer);

    for (int i=0; i < expected_tokens_size; i++) {
        TEST_ASSERT(result[i].type == expected_tokens[i].type);        
        TEST_ASSERT(result[i].literal == expected_tokens[i].literal);        
    }

}
