#include <stdlib.h>
#include <stdio.h>

extern void block_cipher(char *args[]) {
    // Open files
    FILE *input_file = fopen(args[2], "r");
    FILE *output_file = fopen(args[3], "w");
    FILE *key_file = fopen(args[4], "r");

    printf("blockity block!!\n");
    exit(0);
}