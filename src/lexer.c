#include "../include/lexer.h"

Lexer Lexer_new(char *input) {
	Lexer lexer = {

	};
	return lexer;
}

LEX_RESULT lex(Lexer *self) {
	LEX_RESULT result = ERR("You haven't written the lexer\n");	
	return result;
}
