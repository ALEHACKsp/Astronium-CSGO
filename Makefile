BIN_DIR=bin
OBJ_DIR=obj
SRC_DIR=src

CC=g++
CC_FLAGS=-c
LD=g++
LD_FLAGS=

FIND=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call FIND,$d/,$2))

.PHONY: clean rebuild

all: cheat
	@echo ============= Build complete! =============
	
clean:
	@rm -rf $(BIN_DIR)
	@rm -rf $(OBJ_DIR)
	@echo ============= Clean complete! =============

rebuild: clean all
	@echo ============ Rebuild complete! ============

include $(SRC_DIR)/cheat/Makefile