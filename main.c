#include <stdlib.h>
#include <stdio.h>

#include "block.h"
#include "stream.h"

void validate_arguments(int num_args, char *args[])
{
// Ensure there are exactly 5 arguments
   if (num_args != 6)
   {
      fprintf(stderr, "Invalid Argument Number\n");
      exit(1);
   }

   // Validate first argument (Ciper type)
   if ((*args[1] != 'B') && (*args[1] != 'S'))
   {
      fprintf(stderr, "Invalid Function Type\n");
      exit(1);
   }

   // Validate second argument (Input file)
   FILE *input_file = fopen(args[2], "r");

   if (input_file == NULL)
   {
      fprintf(stderr, "Input File Does Not Exist\n");
      exit(1);
   }
      fclose(input_file);

   // Validate fourth argument (Key file)
   FILE *key_file = fopen(args[4], "r");

   if (key_file == NULL)
   {
      fprintf(stderr, "Key File Does Not Exist\n");
      exit(1);
   }
   fclose(key_file);

   // Validate fifth argument (Mode of operation)
   if ((*args[5] != 'E') && (*args[5] != 'D'))
   {
      fprintf(stderr, "Invalid Mode Type\n");
      exit(1);
   }
}

int main(int argc, char *argv[])
{
   validate_arguments(argc, argv);

   if(*argv[1] == 'B') {
      block_cipher(argv);
   }

   else {
      stream_cipher(argv);
   }

   exit(0);
}
