#include "../include/interpreter_test.h"
#include "../../..//include/lexer.h"
#include "../../../include/parser.h"
#include "../../../include/evaluator.h"
#include <string.h>

void test_interpreter(void) {
    char *input = "1 + 1 * 2;"; 
    Lexer lexer = Lexer_new(input);
    Token *tokens = lex(&lexer);

    Parser parser = parser_new(tokens);
    AST tree = parse(&parser);

    char *output = evaluate(tree);
}
