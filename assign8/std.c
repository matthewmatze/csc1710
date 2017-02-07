/*
   Name: Matthew Matze
   Date: 10/02/1994
   Class CSC1710
   Location:~/csc1710/assign8
*/

#include<stdio.h>
#include<math.h>

   int main(void)
{

   char filename[60];
   int grade, sum=0, sqgrade=0, count=0;
   double avg, STD;

   fscanf(stdin, "%s",&filename);
   fprintf(stdout, "\nClass: %s\n", filename);
   fprintf(stdout, "===============The Scores===============\n");
   fscanf (stdin, "%i",&grade);
   while(grade>=0)
   {
   count++; 
   sum+=grade;
   sqgrade+=(grade*grade);
   fprintf (stdout, " %i",grade);
   fscanf (stdin, " %i", &grade);
   }
   avg=(double)sum/count;
   STD=((double)sqrt(   ((double)sqgrade-   (   (   (double)(sum)*(double)(sum)   )/  ((double)count)   )   )   /   (double)(count)   )   );
   fprintf(stdout, "\n===============The Results===============\n");
   fprintf(stdout, "The size of the data set: %i\n", count);
   fprintf(stdout, "Avg = %.2lf\n", avg);
   fprintf(stdout, "STD = %.4lf\n", STD);
   fprintf(stdout, "A range: above %.2lf\n", (avg+(2*STD)));
   fprintf(stdout, "B range: %.2lf to %.2lf\n", (avg+(STD), (avg+(2*STD))));
   fprintf(stdout, "C range: %.2lf to %.2lf\n", (avg-STD), (avg+STD));
   fprintf(stdout, "D range: %.2lf to %.2lf\n", (avg-STD), (avg-(2*STD)));
   fprintf(stdout, "F range: below  %.2lf\n", (avg-(2*STD)));

   return 0;
}
