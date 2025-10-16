CC = gcc
CFLAGS = -Wall -g -Isettings -Ientities
LDFLAGS = -lm

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

TARGET = $(BIN_DIR)/labyrinth

SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/game.c $(SRC_DIR)/matrix.c $(SRC_DIR)/actions.c
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

all: $(TARGET)

production: CFLAGS += -O3 -DNDEBUG
production: LDFLAGS += -s
production: clean $(TARGET)

$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) `sdl2-config --cflags --libs`

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*

rebuild: clean all

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run