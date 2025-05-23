#pragma once
#include "error.h"

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

Lexer Lexer_new(char *input);
Token *lex(Lexer *self);
