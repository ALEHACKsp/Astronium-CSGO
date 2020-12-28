CHEAT_SRC_FILES=$(call FIND,$(SRC_DIR)/cheat,*.cpp)
CHEAT_OBJ_FILES=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CHEAT_SRC_FILES))

CHEAT_CC_FLAGS=-std=c++17 -march=native -fpermissive
CHEAT_LD_FLAGS=-shared

ifeq ($(OS),Windows_NT)
    CHEAT_BIN_FILE=$(BIN_DIR)/cheat.dll
else
    CHEAT_BIN_FILE=$(BIN_DIR)/cheat.so
endif

cheat: $(CHEAT_BIN_FILE)
	
$(CHEAT_BIN_FILE): $(CHEAT_OBJ_FILES)
	@mkdir -p $(dir $@)
	@echo LD $@
	@$(LD) $(LD_FLAGS) $(CHEAT_LD_FLAGS) -o $@ $^

$(OBJ_DIR)/cheat/%.o: $(SRC_DIR)/cheat/%.cpp
	@mkdir -p $(dir $@)
	@echo CC $^
	@$(CC) $(CC_FLAGS) $(CHEAT_CC_FLAGS) -o $@ $^