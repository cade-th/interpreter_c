#pragma once
#include "../../../../utils/include/error.h"

void test_interpreter(void);

#define TEST_CREATE(test_name, test_result_type)	\
typedef struct {					\
	char *name;					\
	test_result_type result;			\
} TestCase_##test_name;							\
TestCase_##test_name TestCase_##test_name = {				\
	#test_name					\
}

