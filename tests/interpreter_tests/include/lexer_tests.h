#pragma once
#include <stdbool.h>
#include "../../../lib/utils_c/include/error.h"

typedef enum {
	NUM_TOKENS,
	INCORRECT_TOKEN,
	LEXER_ERROR
} LEX_TEST_ERROR;

RESULT(bool, LEX_TEST_ERROR) LEX_TEST_RESULT;

LEX_TEST_RESULT lexer_basic_test(void);
