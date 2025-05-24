CC = clang
CFLAGS = -std=c99
# -Wall -Wextra
LDFLAGS = 

# Directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build
LIB_DIR = lib

# Files
#	$(SRC_DIR)/main.c 
SRC_FILES = $(SRC_DIR)/*.c 

LIB_FILES = \
	$(LIB_DIR)/utils_c/src/*.c

TEST_FILES = \
	$(SRC_FILES) \
	$(LIB_FILES) \
	$(TEST_DIR)/main.c \
	$(TEST_DIR)/interpreter_tests/src/*.c

# Binaries
APP_BIN = $(BUILD_DIR)/app
TEST_BIN = $(BUILD_DIR)/tests

# Default target
all: $(APP_BIN)

# App build
$(APP_BIN): $(SRC_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Test build + run
test: $(TEST_BIN)
	@./$(TEST_BIN)

$(TEST_BIN): $(TEST_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(TEST_DIR) -o $@ $^ $(LDFLAGS)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test clean
	$(SRC_DIR)/error/error.c \

PHONY: all test clean
