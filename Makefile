CC = gcc
CFLAGS = -Wall -g -Iinclude
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

gameboy: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f src/*.o gameboy
