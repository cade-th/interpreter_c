#pragma once
#include <stdbool.h>
typedef struct {
	void *value;
	const char *error;
	bool hasError;
} Result;

Result *ResultNewSuccess(void *value);
Result *ResultNewError(const char *error);

void *ResultUnwrap(Result *result);
void *ResultExpect(Result *result, const char *error);
void ResultFree(Result *result);

