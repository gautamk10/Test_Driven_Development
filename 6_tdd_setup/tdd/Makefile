# 1. Compiler and Flags
CC = gcc
CFLAGS = -std=c11 -Wall -I. -Iunity -Isrc -Imocks
LDFLAGS =

# 2. Directories
BUILD_DIR = build
TEST_DIR = test
SRC_DIR = src
MOCKS_DIR = mocks
UNITY_DIR = unity

# 3a. Find all source files
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)
SRC_SOURCES = $(wildcard $(SRC_DIR)/*.c)
MOCK_SOURCES = $(wildcard $(MOCKS_DIR)/*.c)
UNITY_SRC = $(UNITY_DIR)/unity.c

# 3b. Create object list
OBJECTS = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_SOURCES))
OBJECTS += $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_SOURCES))
OBJECTS += $(patsubst $(MOCKS_DIR)/%.c, $(BUILD_DIR)/%.o, $(MOCK_SOURCES))
OBJECTS += $(patsubst $(UNITY_DIR)/%.c, $(BUILD_DIR)/%.o, $(UNITY_SRC))

# 4. Target executable
TARGET = $(BUILD_DIR)/example_test_runner.exe

# 5. Build rules
.PHONY: test clean all
all: $(TARGET)

test: $(TARGET)
	@echo "----- Running Tests -----"
	$(TARGET)
	@echo "-------------------------"

# Link the final executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Compile any .c into .o in build directory
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(MOCKS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(UNITY_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# 6. Clean rule
clean:
	rm -f $(BUILD_DIR)/*.*
