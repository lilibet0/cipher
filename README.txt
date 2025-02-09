README
======

This package includes the following files.

|-- main.c [This is the driver program which will be used to invoke the ciphers.]
|-- block.c [Block cipher is implemented here.]
|-- stream.c [Stream cipher is implemented here.]
|-- block.h [Header file declaring the function exposed from block.c]
|-- stream.h [Header file declaring the function exposed from stream.c]
|-- Makefile [Used for compilation]
|-- README.txt [This file]

To compile:
    make

To run:
    ./cipher <cipher_mode> <existing_input.txt> <output.txt> <existing_key.txt> <encrypt/decrypt>

For example;
    ./cipher B input.txt output.txt key.txt E

