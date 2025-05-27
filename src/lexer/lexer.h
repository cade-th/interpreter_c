#pragma once
#include "../../lib/utils_c/include/error.h"

typedef enum {
	INVALID_TOKEN,
	LEXER_ERR,
	FUNCTION_BODY,

	// Test Errors
	NUM_TOKENS,
	INCORRECT_TOKEN_TYPE,
	INCORRECT_TOKEN_LITERAL,

} lexer_error_t;
ERROR(lexer_error_t) lexer_error;

typedef enum {
	// idk
	ASTERISK = 0,
	ASSIGN = 1,

	// Keywords
	FUNCTION = 2,
	LET = 3,

	ILLEGAL = 4,
	Eof = 5,

	// Identifiers + Literals
	INT = 6,
	IDENT = 7,

	// Operators
	PLUS = 8,
	MINUS = 9,

	// Delimiters
	SEMICOLON = 10,
	COMMA = 11,

	RPAREN = 12,
	LPAREN = 13,
	RBRACKET = 14,
	LBRACKET = 15,

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

// Token functions
Token tok_new(Token_t type, char ch);
Token next_token(Lexer *self);

// Need to write these
void skip_whitespace(Lexer *self);
bool is_letter(char *ch);
bool is_number(char *ch);
char *read_identifier(Lexer *self);
char *read_number(Lexer *self);
Token_t lookup_ident(char *ident);

// Lex functions
void read_char(Lexer *self);
Lexer Lexer_new(char *input);
lexer_error lex(Lexer *self);

// Test functions
void lexer_basic_test(char *input_1, int num_tokens, Token expected_tokens[]);
void run_lexer_tests();
