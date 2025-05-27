#pragma once
#include "../lexer/lexer.h"

typedef enum {
	WRITE_PARSER,
} parser_error_t;
ERROR(parser_error_t) parser_error;

typedef struct {
	Token *tokens;
} Parser;
typedef struct {} AST;

void parser_basic_test(char *input_1);
void run_parser_tests();

Parser parser_new(Token *tokens);

parser_error parse(Parser *self);

