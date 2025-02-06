CC=gcc
FILES=cipher.c
OUT_EXE = cipher
build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES)
clean:
	rm -f *.o $(OUT_EXE)
all: clean build 
