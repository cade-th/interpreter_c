#include "parser.h"
#include "../../lib/utils_c/include/dyn_array.h"

static parser_error parser_mod_error = { .ok = true};

Parser parser_new(Token *tokens, Parser_t type) {
	Parser parser = {
		tokens,		
		embedded,
	};
	return parser;
}

parser_error parse(Parser *self) {
	
	for (int i=0; i < ARRAY_LENGTH(self->tokens); i++) {

	}

	parser_mod_error.ok = false;
	parser_mod_error.type =	WRITE_PARSER;
	return parser_mod_error;
}

