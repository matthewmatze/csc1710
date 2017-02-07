/* Name: Matthew Matze
 * Date: 11/20/13
 * Class: CSC-1710 Fall 2013
 * Location: csc1710/assign13
 * This is an image filter program.  Currently, it only performs one filter.
 * 1) filters a color image into a black and white image.
 */
#include<stdlib.h>
#include<stdio.h>

#include"image.h"

void get_image(const char message[], struct imageType *img);
void put_image(const char message[], struct imageType *img);

int main()
{
   struct imageType orig_image; 
   struct imageType second_image; 
   struct imageType new_image; 

   char type[2];

   printf("==========================\n");
   printf("     Image filtering\n");
   printf("==========================\n");
   printf("         Options\n");
   printf("(c)olor to Black and White\n");
   printf("(m)irror Original Image\n");
   printf("Make Original Image (n)egative\n");
   printf("Blen(d) two images\n");
   printf("(b)ackground replace\n");
   printf("==========================\n");
   printf("Enter one of the above: \n");
   scanf("%1s",type);
   while (type[0] != 'c'&&type[0] != 'm'&&type[0] != 'n'&&type[0] != 'd'&&type[0] != 'b') {
      printf("Invalid input!\n");
      printf("Options: (c)olor,(m)irror, (n)egative, Blen(d), or (b)ackground\n");
      scanf("%1s",type);
   } 

   //since all filters operator on an original image....
   //open file, read in original image, one at a time, and then close the file.
      get_image("original",&orig_image);
   if(type[0] == 'c') {
      cvt_bw(&orig_image, &new_image);
   }
   if (type[0] == 'm') {
      cvt_m(&orig_image, &new_image);
   }
   if (type[0] == 'n') {
      cvt_n(&orig_image, &new_image);
   }
   if (type[0] == 'd') {
      get_image("second",&second_image);
      cvt_d(&orig_image, &second_image, &new_image);
   }
   if (type[0] == 'b') {
      get_image("background",&second_image);
      cvt_b(&orig_image, &second_image, &new_image);
   }
   put_image("new",&new_image);
   return 0;
   }
   void get_image(const char message[], struct imageType *img)
   {
      FILE *infile;
      char image_filename[30];
      //open file, read in image, then close the file.
      printf("Enter the %s image filename (no spaces): ",message);
      scanf("%s",image_filename);
      infile=fopen(image_filename,"r");
      if(infile==NULL) {
         fprintf(stderr,"Error with %s image file: ",message);
         fprintf(stderr,"%s\n",image_filename);
         exit(1);
      }
      read_image(infile, img);
      fclose(infile);
   }
   void put_image(const char message[], struct imageType *img)
   {
   //assignment for Friday - 11-22
      FILE *newfile;
      
      char image_filename[30];
      //open file, write image, then close the file.
      printf("Enter the %s image filename (no spaces): ", message);
      scanf("%s",image_filename);
      newfile=fopen(image_filename,"w");
      if(newfile==NULL) {
         fprintf(stderr,"Error with new image file: ");
         fprintf(stderr,"%s\n",image_filename);
         exit(2);
      }
      write_image(newfile, img);
      fclose(newfile);
   } 
