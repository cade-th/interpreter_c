#include "interpreter_test.h"
#include "../../src/lexer.h"
#include "../../src/parser.h"
#include "../../src/evaluator.h"
#include <string.h>
#include "../unity.h"

void test_interpreter(void) {
    char *input = "1 + 1 * 2;"; 
    Lexer lexer = Lexer_new(input);
    Token *tokens = lex(&lexer);

    Parser parser = parser_new(tokens);
    AST tree = parse(&parser);

    char *output = evaluate(tree);
    TEST_ASSERT(strcmp(output, "4"));
}
