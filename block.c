#include <stdlib.h>
#include <stdio.h>

void encrypt(FILE *input_file, FILE *output_file, char key[])
{
    printf("encrypting!\n");
}

void decrypt(FILE *input_file, FILE *output_file, char key[])
{
    printf("decrypting!\n");
}

void block_cipher(char *args[])
{
    // Open files
    FILE *input_file = fopen(args[2], "r");
    FILE *output_file = fopen(args[3], "w");
    FILE *key_file = fopen(args[4], "r");

    // Get key
    // Key file will contain 16 characters for the block cipher
    char key[16];
    fgets(key, 16 + 1, key_file);

    if (*args[5] == 'E')
    {
        encrypt(input_file, output_file, key);
    }

    else {
        decrypt(input_file, output_file, key);
    }
    
    exit(0);
}