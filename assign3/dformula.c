/*
   Name: Matthew Matze
   Date: 9/2/2013
   Class: csc1710
   Location: Remote or My Dorm
   This program will find the distance that a object will
   fall in free fall for a certain amount of time
*/
#include<stdio.h>

int main(void)
{
   int d, t;

   printf("Enter in the time of freefall: ");
   scanf("%i/n",&t);

   d=(32*(t*t))/2;

   printf("The object would fall %i feet", d);
   
   return 0;
}
