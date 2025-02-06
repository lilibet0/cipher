#include <stdlib.h>
#include <stdio.h>

extern void stream_cipher(char *args[]) {
    // Open files
    FILE *input_file = fopen(args[2], "r");
    FILE *output_file = fopen(args[3], "w");
    FILE *key_file = fopen(args[4], "r");

    printf("dreamy streamy!!\n");
    exit(0);
}