#include "../include/lexer_tests.h"
#include "../../../include/lexer.h"
#include "../../../lib/utils_c/include/dyn_array.h"
#include <stdio.h>
#include <string.h>

void lexer_basic_test(void) {
    lexer_error error;
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
    error = lex(&lexer);    
    int num_tokens;

    if (error.ok) {
    
        Token *tokens = (Token*)error.data;
        num_tokens = ARRAY_LENGTH(tokens);

        if (num_tokens != expected_tokens_size) {
            error.ok = false;
            error.type = NUM_TOKENS;
        }
        if (error.ok) {
                for (int i=0; i < expected_tokens_size; i++) {
                    Token current_token = tokens[i];
                    if(current_token.type != expected_tokens[i].type) {
                        error.ok = false;
                        error.type = INCORRECT_TOKEN_TYPE;
                    }
                    if(strcmp(current_token.literal,expected_tokens[i].literal) != 0) {
                        error.ok = false;
                        error.type = INCORRECT_TOKEN_LITERAL;
                        error.data = current_token.literal;

                    }
                }
                if (error.ok) {
                    printf("Lex Test Basic: PASS\n");
                    return;
                }
        }
    }
            switch (error.type) {
                case INCORRECT_TOKEN_TYPE:
                    printf("Incorrect Token Type: ?\n");
                    break;
                case INCORRECT_TOKEN_LITERAL:
                    printf("Incorrect Token Literal: %s\n", (char *)error.data);
                    break;
                case LEXER_ERR:
                    printf("Lexer had an error\n");
                    break;
                case FUNCTION_BODY:
                    printf("Write the lexer loser\n");
                    break;
                case NUM_TOKENS:
                    printf("Incorrect number of tokens. Expected Tokens: %d, Processed Tokens %d\n", expected_tokens_size, num_tokens);
                    break;
                case INVALID_TOKEN:
                    printf("Lexer caught an invalid token: %c\n", *(char*)error.data);
                    break;
            };
}

void lexer_complex_test(void) {
}
