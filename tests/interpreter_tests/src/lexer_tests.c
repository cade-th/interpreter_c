#include "../include/lexer_tests.h"
#include "../../../include/lexer.h"
#include <stdio.h>
#include <string.h>

LEX_TEST_RESULT lexer_basic_test(void) {
    char* input = "=+(){},;";
    int expected_tokens_size = 9;
    Token expected_tokens[] = {
        {ASSIGN, "="},
        {PLUS, "+"},
        {LPAREN, "("},
        {RPAREN, ")"},
        {LBRACKET, "{"},
        {RBRACKET, "}"},
        {COMMA, ","},
        {SEMICOLON, ";"},
        {Eof, " "}
    };

    Lexer lexer = Lexer_new(input);
    LEX_RESULT lex_result = lex(&lexer);
    if (lex_result.is_ok) {
        for (int i=0; i < expected_tokens_size; i++) {
            if(lex_result.inner.val[i].type != expected_tokens[i].type) {
                LEX_TEST_RESULT result = ERR(INCORRECT_TOKEN_TYPE); 
                return result;
                
            }
            if(strcmp(lex_result.inner.val[i].literal,expected_tokens[i].literal) != 0) {
                printf("Incorrect literal: %s\n", lex_result.inner.val[i].literal);
                LEX_TEST_RESULT result = ERR(INCORRECT_TOKEN_LITERAL);
                return result;
            }
        }
        LEX_TEST_RESULT result = OK(1);
        return result;

    } else {
        printf("%s",UNWRAP_ERR(lex_result));
        LEX_TEST_RESULT result = ERR(LEXER_ERROR);
        return result;
    }

    
}
