.PHONY: clean tidy

CC=gcc
CFLAGS= -Wall  -std=c99 
LFLAGS=-lm

SRC_FOLDER = src
HEADER_FOLDER = include
BUILD_FOLDER = build
BIN_FOLDER = bin

HDR=$(wildcard *.h)
SRC=$(filter-out $(wildcard $(SRC_FOLDER)/*_test.c), $(wildcard $(SRC_FOLDER)/*.c))
OBJ=$(patsubst $(SRC_FOLDER)/%.c, $(BUILD_FOLDER)/%.o, $(SRC))
BIN=$(BIN_FOLDER)/main

CFLAGS_TEST=$(CFLAGS) 
LFLAGS_TEST=$(LFLAGS) -lcheck -lm -lpthread -lrt -lsubunit
SRC_TEST=$(filter-out $(SRC_FOLDER)/main.c, $(wildcard $(SRC_FOLDER)/*.c))
OBJ_TEST=$(patsubst $(SRC_FOLDER)/%.c, $(BUILD_FOLDER)/%.o, $(SRC_TEST))
BIN_TEST=$(BIN_FOLDER)/test

main: $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ) $(LFLAGS)

test: $(OBJ_TEST)
	$(CC) $(CFLAGS_TEST) -o $(BIN_TEST) $(OBJ_TEST) $(LFLAGS_TEST)

$(BUILD_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	$(CC) -c $(CFLAGS) -o $@ $< $(LFLAGS)

$(BUILD_FOLDER)/%_test.o: $(SRC_FOLDER)/%_test.c
	$(CC) -c $(CFLAGS_TEST) -o $@ $< $(LFLAGS_TEST)

clean:
	rm -rf $(OBJ) $(BIN) $(BIN_TEST)

tidy:
	rm -rf $(OBJ)
