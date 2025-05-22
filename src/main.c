// System call provided by posix
#include "lexer.h"
#include "cade_lang.h"

int main(int argc, char* argv[]) {
	Config config = config_build(argc, argv);
	run(config);
	return 0;
}



