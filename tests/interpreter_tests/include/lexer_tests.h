#pragma once
#include <stdbool.h>
#include "../../../lib/utils_c/include/error.h"

RESULT(bool, char *) LEX_TEST_RESULT;

LEX_TEST_RESULT lexer_basic_test(void);
