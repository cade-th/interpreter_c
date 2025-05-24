#pragma once
#include "../lib/utils_c/include/error.h"

typedef enum {
	INT,
	PLUS,
	ASTERISK,
	LET,
	SEMICOLON,
	COMMA,
	Eof,
	ASSIGN,
	IDENT,
	ILLEGAL
} Token_t;

typedef struct {
	Token_t type;
	char *literal;
} Token;

typedef struct {
	char *input;
	int position;
	int read_position;
	char *ch;
} Lexer;

// Return either an array of tokens or an error
RESULT(Token *, char *) LEX_RESULT;

Lexer Lexer_new(char *input);
LEX_RESULT lex(Lexer *self);
