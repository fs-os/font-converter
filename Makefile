
CC=gcc
CFLAGS=-Wall -Wextra
BIN=font-converter

.PHONY: all run clean 

all: $(BIN)

run: $(BIN)
	./$<

clean:
	rm -f $(BIN)

#------------------------------------

$(BIN): src/*.c src/*.h
	$(CC) $(CFLAGS) -o $@ src/main.c

