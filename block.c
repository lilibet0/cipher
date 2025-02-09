#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void encrypt(FILE *input_file, FILE *output_file, char key[16])
{
    bool complete = false;
    char block[16];
    char output[16];
    char ch;

    while (!complete)
    {
        // Get block
        memset(block, (char)129, 16);
        for (int i = 0; i < 16; i++)
        {
            if ((ch = fgetc(input_file)) != EOF)
            {
                block[i] = ch;
            }
            else
            {
                complete = true;
            }
        }

        // XOR in a byte-wise manner
        for (int i = 0; i < 16; i++)
        {
            output[i] = (char)(key[i]) ^ (block[i]);
        }

        // Swap bytes
        int start = 0;
        int end = 15;
        int current_byte = 0;

        while (start < end)
        {
            current_byte = current_byte % 16;

            if ((key[current_byte] % 2) == 1)
            {
                // Swap bytes in block
                ch = output[start];
                output[start] = output[end];
                output[end] = ch;

                end--;
            }
            start++;
            current_byte++;
        }

        for (int i = 0; i < 16; i++)
        {
            fprintf(output_file, "%c", output[i]);
        }
    }
}

void decrypt(FILE *input_file, FILE *output_file, char key[16])
{
    bool complete = false;
    char block[16];
    char output[16];
    char ch;

    while (!complete)
    {
        // Get block
        memset(block, (char)129, 16);
        
        for (int i = 0; i < 16; i++)
        {
            if ((ch = fgetc(input_file)) != EOF)
            {
                block[i] = ch;
            }
            else
            {
                complete = true;
            }
        }

        // Swap bytes
        int start = 0;
        int end = 15;
        int current_byte = 0;

        while (start < end)
        {
            current_byte = current_byte % 16;

            if ((key[current_byte] % 2) == 1)
            {
                // Swap bytes in block
                ch = block[start];
                block[start] = block[end];
                block[end] = ch;

                end--;
            }
            start++;
            current_byte++;
        }

        // XOR in a byte-wise manner
        for (int i = 0; i < 16; i++)
        {
            if(output[i] != (char)129) {
                output[i] = (char)(key[i]) ^ (block[i]);
            }
        }

        for (int i = 0; i < 16; i++)
        {
            // Remove any padding
            if (output[i] != (char)129)
            {
                fprintf(output_file, "%c", output[i]);
            }
            else {
                return;
            }
        }
    }
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

    else
    {
        decrypt(input_file, output_file, key);
    }

    fclose(input_file);
    fclose(key_file);
    fclose(output_file);
    exit(0);
}
