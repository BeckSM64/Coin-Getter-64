V=1
SOURCE_DIR=src
BUILD_DIR=build
RESOURCES_DIR=$(SOURCE_DIR)/resources
AUDIO_DIR=$(RESOURCES_DIR)/audio
AUDIO_OUTPUT_DIR=$(AUDIO_DIR)/audio64files
FILESYSTEM_DIR=$(SOURCE_DIR)/filesystem
WAV_FILES=$(wildcard $(AUDIO_DIR)/*.wav)
TOOLS_DIR=libdragon/tools
TOOLS_AUDIOCONV=$(TOOLS_DIR)/audioconv64/audioconv64
include $(N64_INST)/include/n64.mk

all: coingetter.z64 convert_audio_files build_tools
.PHONY: all

# Object files
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/Player.o $(BUILD_DIR)/Enemy.o

# Require DFS
coingetter.z64: $(BUILD_DIR)/coingetter.dfs

# Compile tools
build_tools:
	@echo "BUILDING TOOLS"
	cd $(TOOLS_DIR) && make

# Convert audio files
convert_audio_files: $(TOOLS_AUDIOCONV)
	@echo "CONVERT AUDIO FILES TO N64 AUDIO FORMAT"
	$(TOOLS_AUDIOCONV) --wav-loop true $(AUDIO_DIR)/*.wav
	mv *.wav64 $(FILESYSTEM_DIR)/

# Tell the DFS which folders/files should be included
$(BUILD_DIR)/coingetter.dfs: $(wildcard $(FILESYSTEM_DIR)/*)

coingetter.z64: N64_ROM_TITLE="Coin Getter"

$(BUILD_DIR)/coingetter.elf: $(OBJS)

clean:
	rm -f $(BUILD_DIR)/* *.z64
.PHONY: clean

-include $(wildcard $(BUILD_DIR)/*.d)
