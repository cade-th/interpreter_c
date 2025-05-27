#include "parser.h"

static parser_error parser_mod_error = { .ok = true};

Parser parser_new(Token *tokens) {
	Parser parser = {
		tokens,		
	};
	return parser;
}

parser_error parse(Parser *self) {
	parser_mod_error.ok = false;
	parser_mod_error.type =	WRITE_PARSER;
	return parser_mod_error;
}

