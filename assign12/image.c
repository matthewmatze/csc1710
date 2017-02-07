/*
 * Name: Matthew Matze 
 * Date: 11/20/13
 * Class: CSC-1710 Fall 2013
 * Location: csc1710/assign12
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"image.h"
//==================================================================
void read_pixel(FILE *in_file, struct pixelType *p)
{
   /*  If you read as characters, then you have to type cast to
   unsigned char.  A conversion issue.
          
   char r,g,b;
   fscanf(in_file,"%hhc",&r);
   fscanf(in_file,"%hhc",&g);
   fscanf(in_file,"%hhc",&b);
                   
   p->red = (unsigned char) r;
   p->green = (unsigned char) g;
   p->blue = (unsigned char) b;
   */
//A BETTER WAY - use the %hhc in the write_pixel function 
   fscanf(in_file,"%hhc",&p->red);
   fscanf(in_file,"%hhc",&p->green);
   fscanf(in_file,"%hhc",&p->blue);

}
//==================================================================
void read_image(FILE *in_file, struct imageType *img)
{
   char newLineChar; 
   int x,y;
   //Please note when a newLineChar is read.  Reason: need to be ready
   //for the next item at the beginning of the line.  To be consistent,
   //it's read everytime and discarded.  Due to the nature of scanf
   //you really only need it while reading the magicNumber and maxColor
   fscanf(in_file,"%[^\n]%c",img->magicNumber,&newLineChar);
   fscanf(in_file,"%[^\n]%c",img->comment,&newLineChar);
   fscanf(in_file,"%d%d%c",&img->width,&img->height,&newLineChar);
   fscanf(in_file,"%d%c",&img->maxColor,&newLineChar);

   for(y=img->height-1;y>=0; y--)
      for(x=0; x<img->width; x++)
         read_pixel(in_file, &img->image[y][x]);
}
//==================================================================
void write_pixel(FILE *out_file, struct pixelType p)
{
   //assignment for Friday - 11-22 
   fprintf(out_file, "%hhc", p.red);
   fprintf(out_file, "%hhc", p.green);
   fprintf(out_file, "%hhc", p.blue);
}
//==================================================================
void write_image(FILE * out_file, struct imageType *img)
{
   //assignment for Friday - 11-22 
   int x,y;
   fprintf(out_file,"%s\n",img->magicNumber);
   fprintf(out_file,"%s\n",img->comment);
   fprintf(out_file,"%d %d\n",img->width,img->height);
   fprintf(out_file,"%d\n",img->maxColor);
   for(y=img->height-1;y>=0; y--)
      for(x=0; x<img->width; x++)
         write_pixel(out_file, img->image[y][x]); 
}
//==================================================================
struct pixelType cvt_pixel_bw(struct pixelType orig_p)
{
   unsigned char r,g,b;
   unsigned char bw;
   struct pixelType new_p;
   r = orig_p.red;
   g = orig_p.green;  
   b = orig_p.blue;  
   bw = (unsigned char)(r*RED_BW_WEIGHT+g*GREEN_BW_WEIGHT+b*BLUE_BW_WEIGHT);
   new_p.red = new_p.green = new_p.blue = bw;
   return new_p;
}
//==================================================================
struct pixelType cvt_pixel_n(struct pixelType orig_p)
{
   unsigned char r,g,b;
   struct pixelType new_p;
   r = orig_p.red;
   g = orig_p.green;  
   b = orig_p.blue;
     
   new_p.red = MAXCOLOR-r;
   new_p.green = MAXCOLOR-g;
   new_p.blue = MAXCOLOR-b;

   return new_p;
}
//==================================================================
void cvt_bw(struct imageType *orig_img, struct imageType *new_img)
{
   int x,y;
   strcpy(new_img->magicNumber, orig_img->magicNumber);
   strcpy(new_img->comment,orig_img->comment);
   new_img->width = orig_img->width;
   new_img->height = orig_img->height;
   new_img->maxColor = orig_img->maxColor;
   for(y=new_img->height-1;y>=0; y--) 
      for(x=0; x<new_img->width; x++) {
         new_img->image[y][x] = cvt_pixel_bw(orig_img->image[y][x]);
      }
}
//==================================================================
void cvt_m(struct imageType *orig_img, struct imageType *new_img)
{
   int x,y;
   struct pixelType temp;
   strcpy(new_img->magicNumber, orig_img->magicNumber);
   strcpy(new_img->comment,orig_img->comment);
   new_img->width = orig_img->width;
   new_img->height = orig_img->height;
   new_img->maxColor = orig_img->maxColor;
   for(y=new_img->height-1;y>=0; y--) 
      for(x=0; x<(new_img->width); x++) {
         temp=new_img->image[y][x];
         new_img->image[y][x] = orig_img->image[y][new_img->width-x-1];
         orig_img->image[y][new_img->width-x-1]=temp;
      }
}
//==================================================================
void cvt_n(struct imageType *orig_img, struct imageType *new_img)
{
   int x,y;
   strcpy(new_img->magicNumber, orig_img->magicNumber);
   strcpy(new_img->comment,orig_img->comment);
   new_img->width = orig_img->width;
   new_img->height = orig_img->height;
   new_img->maxColor = orig_img->maxColor;
   for(y=new_img->height-1;y>=0; y--) 
      for(x=0; x<new_img->width; x++) {
         new_img->image[y][x] = cvt_pixel_n(orig_img->image[y][x]);
      }
}
