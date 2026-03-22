# Makefile per lo stack OSI completo

# Compilatore e flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g

# Cartelle
SRC_DIR = src
OBJ_DIR = build
BIN = osi_stack

# File sorgenti e oggetti
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Target di default
all: $(BIN)

# Link finale
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilazione oggetti
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Creazione cartella build se non esiste
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Pulizia
clean:
	rm -rf $(OBJ_DIR) $(BIN)

.PHONY: all clean