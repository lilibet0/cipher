CC = gcc
CFLAGS += -Wall
FILES=main.c block.c stream.c
OUT_EXE = cipher

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES)

debug: $(FILES)
	$(CC) -g -o $(OUT_EXE) $(FILES)

clean:
	rm -f cipher

all: clean build

