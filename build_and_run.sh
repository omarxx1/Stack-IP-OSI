#!/bin/bash

# Script per compilare e lanciare lo stack OSI in C

# Cartelle
SRC_DIR="src"
INCLUDE_DIR="include"
BUILD_DIR="build"
BIN="osi_stack"

# Crea la cartella build se non esiste
mkdir -p "$BUILD_DIR"

# Compila tutti i file .c in oggetti
echo "Compilazione dei file sorgente..."
OBJ_FILES=()
for SRC_FILE in $SRC_DIR/*.c; do
  OBJ_FILE="$BUILD_DIR/$(basename ${SRC_FILE%.c}.o)"
  gcc -Wall -Wextra -g -I"$INCLUDE_DIR" -c "$SRC_FILE" -o "$OBJ_FILE"
  if [ $? -ne 0 ]; then
    echo "Errore di compilazione in $SRC_FILE"
    exit 1
  fi
  OBJ_FILES+=("$OBJ_FILE")
done

# Link finale
echo "Linking degli oggetti..."
gcc -Wall -Wextra -g -o "$BIN" "${OBJ_FILES[@]}"
if [ $? -ne 0 ]; then
  echo "Errore durante il linking"
  exit 1
fi

# Esecuzione
echo "=== Esecuzione dello stack OSI ==="
./"$BIN"