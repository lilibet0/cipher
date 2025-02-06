#include <stdlib.h>
#include <stdio.h>

extern void stream_cipher(char *args[]) {
    // Open files
    FILE *input_file = fopen(args[2], "r");
    FILE *output_file = fopen(args[3], "w");
    FILE *key_file = fopen(args[4], "r");

    // Get key from keyfile

    // Find length of key
    fseek(key_file, 0, SEEK_END);
    long key_size = ftell(key_file);
    fseek(key_file, 0, SEEK_SET);
    
    // Store key
    char key[key_size];
    fgets(key, key_size + 1, key_file);

    // XOR
    char ch;
    char output;
    int current_key_index = 0;

    while((ch = fgetc(input_file)) != EOF) {
        output = (char)ch^(key[current_key_index % key_size]);
        fprintf(output_file, "%c", output);
        current_key_index++;
    }

    exit(0);
}