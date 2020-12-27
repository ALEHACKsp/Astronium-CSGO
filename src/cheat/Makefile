CHEAT_SRC_FILES=$(call FIND,$(SRC_DIR)/cheat,*.cpp)
CHEAT_OBJ_FILES=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CHEAT_SRC_FILES))

ifeq ($(OS),Windows_NT)
    CHEAT_BIN_FILE=$(BIN_DIR)/cheat.dll
else
    CHEAT_BIN_FILE=$(BIN_DIR)/cheat.so
endif

cheat: $(CHEAT_BIN_FILE)
	
$(CHEAT_BIN_FILE): $(CHEAT_OBJ_FILES)
	@mkdir -p $(dir $@)
	@$(LD) $(LD_FLAGS) -o $@ $^
	@echo LD $(LD_FLAGS) $^

$(OBJ_DIR)/cheat/%.o: $(SRC_DIR)/cheat/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CC_FLAGS) -o $@ $^
	@echo CC $(CC_FLAGS) $^