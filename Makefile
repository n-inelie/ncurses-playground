CC := clang
CFLAGS := -Wall -Wextra -Werror -pedantic
DEBUG_FLAGS := -ggdb
INCLUDE := -lm -lncurses
TARGET := playground

INCLUDE_DIR := include
SOURCE_DIR := src
BUILD_DIR := build

SOURCES := $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS := $(patsubst $(SOURCE_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

$(shell mkdir -p $(BUILD_DIR))

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) $(INCLUDE)


$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET)
