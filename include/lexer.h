#pragma once
#include "error.h"

typedef enum {
	Ident,
	Integer,
	Illegal,
	EOF,
	Int,
	Assign,
	Plus,
	Asterisk,
	Slash,
	Minus,
	Comma,
	Semicolon,
	Lparen,
	Rparen,
	Lbrace,
	Rbrace,
	Function,
	Let
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
