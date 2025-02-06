#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void validate_arguments(int num_args, char *args[], FILE *input_file, FILE *key_file)
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
   input_file = fopen(args[2], "r");

   if (input_file == NULL)
   {
      fprintf(stderr, "Input File Does Not Exist\n");
      exit(1);
   }

   // Validate fourth argument (Key file)
   key_file = fopen(args[4], "r");

   if (key_file == NULL)
   {
      fprintf(stderr, "Key File Does Not Exist\n");
      exit(1);
   }

   // Validate fifth argument (Mode of operation)
   if ((*args[5] != 'E') && (*args[5] != 'D'))
   {
      fprintf(stderr, "Invalid Mode Type\n");
      exit(1);
   }
}

int main(int argc, char *argv[])
{
   FILE *input_file, *output_file, *key_file;
   output_file = fopen(argv[3], "w");

   // Validate arguments
   validate_arguments(argc, argv, input_file, output_file);
   
   printf("true\n");

   exit(0);
}
