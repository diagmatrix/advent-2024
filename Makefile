CXX := g++
CXXFLAGS := -Wall -Wextra -O2
SRC_DIR := src
BIN_DIR := bin

DAYS := 1 2 3
SOURCES := $(addprefix $(SRC_DIR)/day_, $(addsuffix .cpp, $(DAYS)))
OUTPUTS := $(addprefix $(BIN_DIR)/solution_, $(DAYS))

.PHONY: all
all: $(OUTPUTS)

$(BIN_DIR)/solution_%: $(SRC_DIR)/day_%.cpp $(SRC_DIR)/utils.hpp | $(BIN_DIR)
	@echo "Compiling solution for day $*..."
	$(CXX) $(CXXFLAGS) $< $(SRC_DIR)/utils.hpp -o $@

$(BIN_DIR):
	@echo "Creating directory for binaries..."
	@mkdir -p $@

.PHONY: clean
clean:
	@echo "Cleaning up..."
	rm -rf $(BIN_DIR)