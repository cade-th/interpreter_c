#include "lexer.h"
#include "../../lib/utils_c/include/dyn_array.h"
#include <string.h>
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

Token_t lookup_ident(char *ident) {
    if (strcmp(ident, "let") == 0) {
        return LET;
    } else if (strcmp(ident, "fn") == 0) {
        return FUNCTION;
    } else {
        return IDENT;
    }
}

void skip_whitespace(Lexer *self) {
    while (self->ch == ' ' || self->ch == '\t' || self->ch == '\n' || self->ch == '\r') {
        read_char(self);
    }
}

bool is_letter(char *ch) {
    return ('a' <= *ch && *ch <= 'z') || ('A' <= *ch && *ch <= 'Z') || *ch == '_';
}

bool is_number(char *ch) {
    return '0' <= *ch && *ch <= '9';
}

char *read_identifier(Lexer *self) {
    int start_pos = self->position;
    while (is_letter(&self->ch) || is_number(&self->ch)) {
        read_char(self);
    }
    
    int length = self->position - start_pos;
    char *ident = malloc(length + 1);
    strncpy(ident, self->input + start_pos, length);
    ident[length] = '\0';
    return ident;
}

char *read_number(Lexer *self) {
    int start_pos = self->position;
    while (is_number(&self->ch)) {
        read_char(self);
    }
    
    int length = self->position - start_pos;
    char *number = malloc(length + 1);
    strncpy(number, self->input + start_pos, length);
    number[length] = '\0';
    return number;
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

	skip_whitespace(self);
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
		case '*': tok = tok_new(ASTERISK,self->ch); break;
		case '-': tok = tok_new(MINUS, self->ch); break;
		case 0: {
			tok = (Token){
				Eof,
				" "
			};
			break;
		}
	default: {
	    // write map for identifiers
	    if (is_letter(&self->ch)) {
		char *ident = read_identifier(self);
		tok.type = lookup_ident(ident); // now distinguishes keywords
		tok.literal = ident;
		return tok;
	    } else if (is_number(&self->ch)) {
                char *num = read_number(self);
                tok.type = INT; // Assuming INT is a Token_t for integers
                tok.literal = num;
                return tok; // Return early since read_number advances position
            } else {
                tok = tok_new(ILLEGAL, self->ch);
                THROW(error, char, self->ch);
                read_char(self);
            }
        }
			}
	read_char(self);
	return tok;
}

lexer_error lex(Lexer *self) {
    Token *tokens = DYN_ARRAY(Token);    
    bool should_lex = true;

    while (should_lex) {
        Token current_tok = next_token(self);    
        if (!error.ok) { 
            should_lex = false; 
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

