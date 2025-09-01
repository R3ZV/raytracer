CC = gcc
CFLAGS = -std=c23 -Wall -Wextra -Wpedantic -Wshadow -Wconversion \
         -Wpointer-arith -Wcast-qual -Wstrict-prototypes -Wmissing-prototypes \
         -g3 -O0 -fsanitize=address,undefined,leak
LDFLAGS = -lm -fsanitize=address,undefined,leak

SRC_DIR = src
BUILD_DIR = build

CFILES = $(SRC_DIR)/main.c $(SRC_DIR)/vec3.c $(SRC_DIR)/colors.c $(SRC_DIR)/ray.c
OBJFILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(CFILES))

TARGET = $(BUILD_DIR)/main

run: $(TARGET)
	./$(TARGET) > img.ppm

$(TARGET): $(OBJFILES)
	$(CC) $(OBJFILES) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) img.ppm

.PHONY: all run clean
