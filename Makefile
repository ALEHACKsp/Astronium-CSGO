BIN_DIR=bin
OBJ_DIR=obj
SRC_DIR=src

FIND=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call FIND,$d/,$2))

CC=g++
CC_FLAGS=-c
LD=g++
LD_FLAGS=

.PHONY: clean rebuild

all: cheat
	@echo ============= Build complete! =============
	
clean:
	@rm -rf $(BIN_DIR)
	@rm -rf $(OBJ_DIR)

rebuild: all

include $(SRC_DIR)/cheat/Makefile