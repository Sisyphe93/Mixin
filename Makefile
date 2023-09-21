CC := g++

TARGET_EXEC := mixin

BUILD_DIR := ./build
SRC_DIRS := ./src
SRC_DIRS := ./includes

CFLAGS := -Wall -Werror -v

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')
INCLDS := $(shell find $(SRC_DIRS) -name '*.hpp')

all: $(OBJDIRECTORY)
	$(CC) -c $(SRCS) -o $(TARGET_EXEC)

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(TARGET_EXEC)