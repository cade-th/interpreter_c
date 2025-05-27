#include "../include/lexer.h"
#include "../lib/utils_c/include/dyn_array.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

lexer_error error = { .ok = true}; // Initialize error

Lexer Lexer_new(char *input) {
	Lexer lexer = {
		input,
		.position = 0,
	};
	read_char(&lexer);
	return lexer;
}

// Figure this out somehow
Token tok_new(Token_t type, char ch) {
    Token tok;
    tok.type = type;
    tok.literal = malloc(2);
    tok.literal[0] = ch;
    tok.literal[1] = '\0';
    return tok;
}


// Gives the next character and advance the position in the input string
void read_char(Lexer *self) {
	if (self->read_position >= (int)strlen(self->input)) {
		self->ch = 0;
	} else {
		self->ch = self->input[self->read_position];
	}
	self->position = self->read_position;
	self->read_position += 1;
}

Token next_token(Lexer *self) {
	Token tok;

	// not doing this causes a segfault
	tok = (Token) {
		Eof,
		" "
	};

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
		default: 
			tok = tok_new(ILLEGAL, self->ch);
			THROW(error,char,self->ch);
			break;
	}
	read_char(self);
	return tok;
}

lexer_error lex(Lexer *self) {
    Token *tokens = DYN_ARRAY(Token);    
    bool should_lex = true;

    while (should_lex) {
        Token current_tok = next_token(self);    
        if (!error.ok) { // Check if an error occurred in next_token
            should_lex = false; // Exit loop on error
            break;
        }
        ARRAY_PUSH(tokens, current_tok);
        if (current_tok.type == Eof) {
            error.data = tokens;
            should_lex = false;
        }
    }
    return error;
}

