#pragma once
#include "../lib/utils_c/include/error.h"

typedef enum {
	INVALID_TOKEN,
	NUM_TOKENS,
	INCORRECT_TOKEN_TYPE,
	INCORRECT_TOKEN_LITERAL,
	LEXER_ERR,
	FUNCTION_BODY,
} lexer_error_t;
ERROR(lexer_error_t) lexer_error;

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

Token tok_new(Token_t type, char ch);
void read_char(Lexer *self);
Lexer Lexer_new(char *input);
lexer_error lex(Lexer *self);
Token next_token(Lexer *self);
