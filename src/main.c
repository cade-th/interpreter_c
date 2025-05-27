#include "interpreter.h"
#include "lexer/lexer.h"

void run_app(int argc, char *argv) {
	Config config = config_build(argc, &argv);
	run(config);
}

void run_tests() {
	run_lexer_tests();		
}

/*
int main(int argc, char* argv[]) {
	// run_app(argc, *argv);
	run_tests();
}
*/


int main() {
	run_tests();
}




