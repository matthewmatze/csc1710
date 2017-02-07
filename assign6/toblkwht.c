/*
   Name: Matthew Matze
   Date: 9/23/2013
   Class: CSC1710
   Location: ~/csc1710/assign6
*/

#include<stdio.h>

   int main(void)
{
   double black;
   int  red, green, blue, total, i;
   int  width, height, maxcode;
   char imageType[3];
   char comment[256];
   char newlinechar; 

   i=0;
   scanf("%[^\n]%c",imageType,&newlinechar);
   scanf(" %[^\n]%c",comment,&newlinechar);
   scanf("%d %d",&width, &height);
   scanf("%i",&maxcode);
   printf("%s\n", imageType);
   printf("%s\n", comment);
   printf("%d %d\n", width, height);
   printf("%i\n", maxcode);
   total=width*height; 

   while(i<total)
   {
      scanf("%i",&red);
      scanf("%i",&green);
      scanf("%i",&blue);  

      black = ((red*.3)+(green*.6)+(blue*.1));
    
      red=(int)black;
      green=(int)black;
      blue=(int)black;     

      printf("%i\n",red);
      printf("%i\n",green);
      printf("%i\n",blue);

      i++;
   }

   printf("%s\n",imageType);
   printf("%s\n",comment);

   return 0;

}
