#include "parser.h"
#include <stdio.h>

void run_parser_tests() {
	
	// char *input_1 = "=+(){},;";
    
	char *input_2 = "			\
		let five = 5;                   \
		let ten = 10;                   \
		let add = fn(x, y) {            \
		x + y;                          \
		};                              \
		let result = add(five, ten);    \
	";



	parser_basic_test(input_2);	
}
void parser_basic_test(char *input_1) {

	Lexer lexer = Lexer_new(input_1);
	lexer_error lex_error = lex(&lexer);
	Token *tokens = (Token*)lex_error.data;

	Parser parser = parser_new(tokens);
	parser_error parser_error = parse(&parser);

	if (parser_error.ok) {
		printf("Parser Test: Success\n");
		return;
	}

	printf("Parser Test: Fail\n");
	switch (parser_error.type) {
		case WRITE_PARSER:
			printf("Write the parser loser\n");
			break;
	};
		
}
