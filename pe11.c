#include <stdlib.h>
#include <stdio.h>

#include "bmp.h"

int main(int argc,char **argv){
  //counter for number of operations;
  int counter = 0;
  FILE* fptr_in = NULL;
  FILE* fptr_out = NULL;
  BMP_Image *image = NULL;
  if(argc < 4){
    fprintf(stderr,"Not enough arguments");
    return EXIT_FAILURE;
  }
  while(counter <= (argc-3)){
   if(argv[counter+1] = "-v"){
       fprintf(stderr,"push -v");
     }else if(argv[counter+1] = "-h"){
       fprintf(stderr,"push -v");
     }else{
       fprintf(stderr,"free unkown input");
       return EXIT_FAILURE;
     }
  }

  fptr_in = fopen(argv[argc-2],"r");
  image = Read_BMP_Image(fptr_in);
  Free_BMP_Image(BMP_Image*image);

  fclose(fptr_in);
  return EXIT_SUCCESS;
} 
