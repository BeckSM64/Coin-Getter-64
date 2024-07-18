V=1
SOURCE_DIR=src
BUILD_DIR=build
RESOURCES_DIR=$(SOURCE_DIR)/resources
AUDIO_DIR=$(RESOURCES_DIR)/audio
AUDIO_OUTPUT_DIR=$(AUDIO_DIR)/audio64files
FONT_DIR=$(RESOURCES_DIR)/fonts
FILESYSTEM_DIR=$(SOURCE_DIR)/filesystem
WAV_FILES=$(wildcard $(AUDIO_DIR)/*.wav)
TOOLS_DIR=libdragon/tools
TOOLS_AUDIOCONV=$(TOOLS_DIR)/audioconv64/audioconv64
TOOLS_MKFONT=$(TOOLS_DIR)/mkfont/mkfont
TOOLS_CHECKSUM64=$(TOOLS_DIR)/chksum64
include $(N64_INST)/include/n64.mk

all: build_tools convert_audio_files convert_font_files coingetter.z64 checksum
.PHONY: all

# Object files
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/Player.o $(BUILD_DIR)/Enemy.o $(BUILD_DIR)/Game.o $(BUILD_DIR)/AudioManager.o $(BUILD_DIR)/MainMenu.o

# Require DFS
coingetter.z64: $(BUILD_DIR)/coingetter.dfs

# Compile tools
build_tools:
	@echo "BUILDING TOOLS"
	cd $(TOOLS_DIR) && make

# Convert audio files
convert_audio_files: $(TOOLS_AUDIOCONV)
	@echo "CONVERT AUDIO FILES TO N64 AUDIO FORMAT"
	$(TOOLS_AUDIOCONV) --wav-loop true $(AUDIO_DIR)/*.mp3
	mv *.wav64 $(FILESYSTEM_DIR)/

convert_font_files: $(TOOLS_MKFONT)
	@echo "CONVERT FONT FILES TO N64 FONT FORMAT"
	$(TOOLS_MKFONT) --help
	$(TOOLS_MKFONT) --size 48 $(FONT_DIR)/RetroComputer.ttf
	mv *.font64 $(FILESYSTEM_DIR)/

# Tell the DFS which folders/files should be included
$(BUILD_DIR)/coingetter.dfs: $(wildcard $(FILESYSTEM_DIR)/*)

coingetter.z64: N64_ROM_TITLE="Coin Getter"

$(BUILD_DIR)/coingetter.elf: $(OBJS)

checksum: $(TOOLS_CHECKSUM64)
	@echo "RUNNING CHECKSUM ON ROM"
	$(TOOLS_CHECKSUM64) coingetter.z64

clean:
	rm -f $(BUILD_DIR)/* *.z64
.PHONY: clean

-include $(wildcard $(BUILD_DIR)/*.d)
