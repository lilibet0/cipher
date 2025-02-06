#include <stdbool.h> 
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) 
{ 
   // Validate arguments
   // Ensure there are exactly 5 arguments
   if(argc != 6) {
      fprintf(stderr, "Invalid Argument Number\n");
        exit(1);
   }

   // Validate first argument (Ciper type)
   if((*argv[1] != 'B') && (*argv[1] != 'S')) {
      fprintf(stderr, "Invalid Function Type\n");
        exit(1);
   }

   // Validate second argument (Input file)
   FILE* input_file;
   input_file = fopen(argv[2], "r");

   if(input_file == NULL) {
      fprintf(stderr, "Input File Does Not Exist\n");
        exit(1);
   }

   // Validate third argument (output file)/ Create output file
   FILE* output_file;
   output_file = fopen(argv[3], "w");

   if(output_file == NULL) {
      fprintf(stderr, "Output File Does Not Exist\n");
        exit(1);
   }

   // Validate fourth argument (Key file)
   FILE* key_file;
   key_file = fopen(argv[4], "r");

   if(key_file == NULL) {
      fprintf(stderr, "Key File Does Not Exist\n");
        exit(1);
   }

   // Validate fifth argument (Mode of operation)
   if((*argv[5] != 'E') && (*argv[5] != 'D')) {
      fprintf(stderr, "Invalid Mode Type\n");
        exit(1);
   }

   printf("true\n");

   exit(0);
}
