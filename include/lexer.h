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
	ILLEGAL,

	RPAREN,
	LPAREN,
	RBRACKET,
	LBRACKET
} Token_t;

typedef struct {
	Token_t type;
	char *literal;
} Token;

typedef struct {
	char *input;
	int position; // currrent position in the input (points to the current char
	int read_position; // current reading position in the input (after current char)
	char ch; // current char under examination
} Lexer;

// Return either an array of tokens or an error
RESULT(Token *, char *) LEX_RESULT;
RESULT(Token, char *) TOKEN_RESULT;

Token tok_new(Token_t type, char ch);

void read_char(Lexer *self);
Lexer Lexer_new(char *input);
LEX_RESULT lex(Lexer *self);
TOKEN_RESULT next_token(Lexer *self);
