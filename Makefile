CC=gcc
FILES=cipher.c
OUT_EXE = Driver
build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES)
clean:
	rm -f *.o $(OUT_EXE)
all: clean build 
