V=1
SOURCE_DIR=src
BUILD_DIR=build
include $(N64_INST)/include/n64.mk

all: coingetter.z64
.PHONY: all

OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/Player.o $(BUILD_DIR)/Enemy.o

# Require DFS
coingetter.z64: $(BUILD_DIR)/coingetter.dfs

# Tell the DFS which folders/files should be included
$(BUILD_DIR)/coingetter.dfs: $(wildcard $(SOURCE_DIR)/filesystem/*)

coingetter.z64: N64_ROM_TITLE="Coin Getter"

$(BUILD_DIR)/coingetter.elf: $(OBJS)

clean:
	rm -f $(BUILD_DIR)/* *.z64
.PHONY: clean

-include $(wildcard $(BUILD_DIR)/*.d)
