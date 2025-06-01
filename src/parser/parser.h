#pragma once
#include "../lexer/lexer.h"

typedef enum {
	WRITE_PARSER,
} parser_error_t;
ERROR(parser_error_t) parser_error;

typedef enum {
	embedded,
	toy,
	pratt,
} Parser_t;

typedef struct {
	Token *tokens;
	Parser_t type;
} Parser;
typedef struct {} AST;

void parser_basic_test(char *input_1);
void run_parser_tests();

Parser parser_new(Token *tokens, Parser_t type);

parser_error parse(Parser *self);

