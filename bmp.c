#include <stdlib.h>
#include <stdio.h>

#include "bmp.h"

/* check whether a header is valid
 * assume that header has been read from fptr
 * the position of the indicator of fptr is not certain
 * could be at the beginning of the file, end of the file or 
 * anywhere in the file
 * note that the check is only for this exercise/assignment
 * in general, the format is more complicated
 */

int Is_BMP_Header_Valid(BMP_Header* header, FILE *fptr) {
  // Make sure this is a BMP file
  if (header->type != 0x4d42) {
     return FALSE;
  }
  // skip the two unused reserved fields

  // check the offset from beginning of file to image data
  // essentially the size of the BMP header
  // BMP_HEADER_SIZE for this exercise/assignment
  if (header->offset != BMP_HEADER_SIZE) {
     return FALSE;
  }
      
  // check the DIB header size == DIB_HEADER_SIZE
  // For this exercise/assignment
  if (header->DIB_header_size != DIB_HEADER_SIZE) {
     return FALSE;
  }

  // Make sure there is only one image plane
  if (header->planes != 1) {
    return FALSE;
  }
  // Make sure there is no compression
  if (header->compression != 0) {
    return FALSE;
  }

  // skip the test for xresolution, yresolution

  // ncolours and importantcolours should be 0
  if (header->ncolours != 0) {
    return FALSE;
  }
  if (header->importantcolours != 0) {
    return FALSE;
  }
  
  // Make sure we are getting 24 bits per pixel
  // or 16 bits per pixel
  // only for this assignment
  if (header->bits != 24 && header->bits != 16) {
    return FALSE;
  }

  // fill in extra to check for file size, image size
  // based on bits, width, and height

  //set at the beggining
  fseek(fptr,0,SEEK_END);
  unsigned long int sizeFile = ftell(fptr);

  if(sizeFile != header->size){
    return NULL;
  }
  if((sizeFile-54) != header->imagesize){
    return NULL;
  }
  

  //find need padding
  int bytePerPixel = header->bits/8;
  int padNeed = (header->width*bytePerPixel)%4;
  
  if(padNeed != 0){
    padNeed = 4 - padNeed;
  }

  if(header->imagesize != ((header->width*bytePerPixel)+padNeed)){
    return NULL;
  }

  return TRUE;
}

/* The input argument is the source file pointer. 
 * The function returns an address to a dynamically allocated BMP_Image only 
 * if the file * contains a valid image file 
 * Otherwise, return NULL
 * If the function cannot get the necessary memory to store the image, also 
 * return NULL
 * Any error messages should be printed to stderr
 */
BMP_Image *Read_BMP_Image(FILE* fptr) {

  // go to the beginning of the file

   BMP_Image *bmp_image = NULL;

  //Allocate memory for BMP_Image*;




  //Read the first 54 bytes of the source into the header





  // if read successful, check validity of header





  // Allocate memory for image data




 
  // read in the image data

  return bmp_image;
}

/* The input arguments are the destination file pointer, BMP_Image *image.
 * The function write the header and image data into the destination file.
 * return TRUE if write is successful
 * FALSE otherwise
 */
int Write_BMP_Image(FILE* fptr, BMP_Image* image) 
{
   // go to the beginning of the file

   // write header


   // write image data

   return TRUE;
}

/* The input argument is the BMP_Image pointer. The function frees memory of 
 * the BMP_Image.
 */
void Free_BMP_Image(BMP_Image* image) {




}

// Given a BMP_Image, create a new image that is a reflection 
// of the given image
// It could be a horizontal reflection (with the vertical mirror 
// being placed at the center of the image) 
// It could be a vertical reflection (with the horizontal mirror
// being placed at the center of the image)
// It could be a horizontal reflection followed by a vertical
// reflection (or equivalently, a vertical reflection followed by
// horizontal reflection).
// hrefl == 1 implies that a horizontal reflection should take place
// hrefl == 0 implies that a horizontal reflection should not take place
// vrefl == 1 implies that a vertical reflection should take place
// vrefl == 0 implies that a vertical reflection should not take place

BMP_Image *Reflect_BMP_Image(BMP_Image *image, int hrefl, int vrefl)
{
   // create a new image reflected from the given image
   BMP_Image *t_image = NULL;

   return t_image;
}

