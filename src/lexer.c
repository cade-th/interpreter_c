#include "../include/lexer.h"
#include "../lib/utils_c/include/dyn_array.h"
#include <string.h>
#include <stdio.h>

Lexer Lexer_new(char *input) {
	Lexer lexer = {
		input,
	};
	read_char(&lexer);
	return lexer;
}

Token tok_new(Token_t type, char ch) {
	// This is the size limit for token literals rn ig
	char literal[20];
	sprintf(literal,"%c",ch);

	Token tok = {
		type,
		literal
	};
	return tok;
}

char *tokens_to_string(Token *tokens) {
		
}

// Gives the next character and advance the position in the input string
void read_char(Lexer *self) {
	if (self->read_position >= strlen(self->input)) {
		self->ch = 0;
	} else {
		self->ch = self->input[self->read_position];
	}
	self->position = self->read_position;
	self->read_position += 1;
}

TOKEN_RESULT next_token(Lexer *self) {
	
	Token tok;

	switch (self->ch) {
		case '=': tok = tok_new(ASSIGN, self->ch); break;
		case '+': tok = tok_new(PLUS, self->ch); break;
		case '(': tok = tok_new(LPAREN, self->ch); break;
		case ')': tok = tok_new(RPAREN, self->ch); break;
		case '{': tok = tok_new(LBRACKET, self->ch); break;
		case '}': tok = tok_new(RBRACKET, self->ch); break;
		case ',': tok = tok_new(COMMA, self->ch); break;
		case ';': tok = tok_new(SEMICOLON, self->ch); break;
		case 0: {
			tok = (Token){
				Eof,
				" "
			};
			break;
		}
		default: {
			TOKEN_RESULT result = ERR("Unrecognized Token\n");
			return result;
		}
	}
	read_char(self);
	TOKEN_RESULT result = OK(tok);
	return result;
}
LEX_RESULT lex(Lexer *self) {

	Token *tokens = DYN_ARRAY(Token);	

	while(1) {
		TOKEN_RESULT tok_result = next_token(self);	
		if (tok_result.is_ok) {
			ARRAY_PUSH(tokens,tok_result.inner.val);
			if (tok_result.inner.val.type == Eof) {
				LEX_RESULT result = OK(tokens);
				return result;
			}
		}
		else {
			LEX_RESULT result = ERR(tok_result.inner.err);
			return result;
		}
	}
}
