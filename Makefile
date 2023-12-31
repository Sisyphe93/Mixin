# Color codes
RED := \033[0;31m
GREEN := \033[0;32m
NC := \033[0m  # No Color

# Hide all commands
.SILENT:

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

# Compiler and compiler flags
CXX := g++
CXXFLAGS := -g -std=c++11 -Wall -Iincludes `sdl2-config --cflags`
VALGRINDFLAGS := --leak-check=full \
				--show-leak-kinds=all \
				--track-origins=yes\
				--verbose\
				--log-file=valgrind-out.txt
SDL2_LIBS := `sdl2-config --libs`
SDL2_IMAGE_LIBS := `sdl2-config --libs` `pkg-config SDL2_image --libs`
LDFLAGS := $(SDL2_LIBS) $(SDL2_IMAGE_LIBS)

# Source files
SRCS := $(shell find $(SRC_DIR) -type f -name '*.cpp')
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
CLS := $(shell clear)

# Executable name
EXEC := $(BIN_DIR)/Mixin

# Targets
.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	@mkdir -p $(BIN_DIR)
	@echo "$(GREEN)Linking executable:$(NC) $@"
	$(CXX) $^ -o $@ $(LDFLAGS)
	@echo "$(GREEN)Build complete!$(NC)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "$(GREEN)Compiling:$(NC) $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@ || { echo "$(RED)Compilation failed:$(NC) $?"; exit 1; }
	@echo "$(GREEN)Compilation complete:$(NC) $@"

test-leak: 
	@valgrind $(VALGRINDFLAGS) $(EXEC)

clean:
clean:
	@echo "$(RED)Cleaning up:$(NC) $(BUILD_DIR) $(BIN_DIR)"
	@for file in $(BUILD_DIR)/* $(BIN_DIR)/*; do \
		if [ -f "$$file" ]; then \
			echo "$(RED)Removed:$(NC) $$file"; \
			rm -f "$$file"; \
		fi \
	done
	echo "$(RED)Removed:$(NC) $(BUILD_DIR)";
	rm -rf $(BUILD_DIR)
	echo "$(RED)Removed:$(NC) $(BIN_DIR)";
	rm -rf $(BIN_DIR)
	@echo "$(GREEN)Cleaned up!$(NC)"

