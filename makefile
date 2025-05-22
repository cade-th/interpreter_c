CC = clang
CFLAGS = -Wall -Wextra -std=c99

# Directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# Files
#	$(SRC_DIR)/main.c 
SRC_FILES = \
	$(SRC_DIR)/cade_lang.c \
	$(SRC_DIR)/parser/parser.c \
	$(SRC_DIR)/lexer/lexer.c \
	$(SRC_DIR)/evaluator/evaluator.c \
	$(SRC_DIR)/error/error.c 

TEST_FILES = \
	$(SRC_FILES) \
	$(TEST_DIR)/main.c \
	$(TEST_DIR)/unity.c \
	$(TEST_DIR)/interpreter_tests/interpreter_test.c 

# Binaries
APP_BIN = $(BUILD_DIR)/app
TEST_BIN = $(BUILD_DIR)/tests

# Default target
all: $(APP_BIN)

# App build
$(APP_BIN): $(SRC_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Test build + run
test: $(TEST_BIN)
	@./$(TEST_BIN)

$(TEST_BIN): $(TEST_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(TEST_DIR) -o $@ $^

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test clean
	$(SRC_DIR)/error/error.c \

TEST_FILES = \
	$(SRC_FILES) \
	$(TEST_DIR)/main.c \
	$(TEST_DIR)/unity.c \
	$(TEST_DIR)/interpreter_tests/interpreter_test.c 

# Binaries
APP_BIN = $(BUILD_DIR)/app
TEST_BIN = $(BUILD_DIR)/tests

# Default target
all: $(APP_BIN)

# App build
$(APP_BIN): $(SRC_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Test build + run
test: $(TEST_BIN)
	@./$(TEST_BIN)

$(TEST_BIN): $(TEST_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(TEST_DIR) -o $@ $^

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test clean
	$(SRC_DIR)/error/error.c \

TEST_FILES = \
	$(SRC_FILES) \
	$(TEST_DIR)/main.c \
	$(TEST_DIR)/unity.c \
	$(TEST_DIR)/interpreter_tests/interpreter_test.c 

# Binaries
APP_BIN = $(BUILD_DIR)/app
TEST_BIN = $(BUILD_DIR)/tests

# Default target
all: $(APP_BIN)

# App build
$(APP_BIN): $(SRC_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Test build + run
test: $(TEST_BIN)
	@./$(TEST_BIN)

$(TEST_BIN): $(TEST_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(TEST_DIR) -o $@ $^

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test clean
	$(SRC_DIR)/error/error.c \

TEST_FILES = \
	$(SRC_FILES) \
	$(TEST_DIR)/main.c \
	$(TEST_DIR)/unity.c \
	$(TEST_DIR)/interpreter_tests/interpreter_test.c 

# Binaries
APP_BIN = $(BUILD_DIR)/app
TEST_BIN = $(BUILD_DIR)/tests

# Default target
all: $(APP_BIN)

# App build
$(APP_BIN): $(SRC_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Test build + run
test: $(TEST_BIN)
	@./$(TEST_BIN)

$(TEST_BIN): $(TEST_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(TEST_DIR) -o $@ $^

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test clean
