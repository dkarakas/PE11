#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "bmp.h"

int main(int argc,char **argv){
  //counter for number of operations;
  int counter = 0;
  FILE* fptr_in = NULL;
  FILE* fptr_out = NULL;
  BMP_Image *image = NULL;
  if(argc < 4){
    fprintf(stderr,"Not enough arguments\n");
    return EXIT_FAILURE;
  }
  while(counter < (argc-3)){
   if(!strcmp(argv[counter+1],"-v")){
       fprintf(stderr,"push -v\n");
       counter++;
     }else if(!strcmp(argv[counter+1],"-h")){
       fprintf(stderr,"push -h\n");
       counter++;
     }else{
       fprintf(stderr,"free unkown input\n");
       return EXIT_FAILURE;
     }
  }

  fptr_in = fopen(argv[argc-2],"r");
  if(fptr_in == NULL){
    fprintf(stderr,"can't open file. free linked list.\n");
    return EXIT_FAILURE;
  }
  fptr_out = fopen(argv[argc-1],"w");
  if(fptr_out == NULL){
    fprintf(stderr,"can't open file. free linked list and input file.\n");
    return EXIT_FAILURE;
  }
  image = Read_BMP_Image(fptr_in);
  Free_BMP_Image(image);

  fclose(fptr_in);
  fclose(fptr_out);
  return EXIT_SUCCESS;
} 
