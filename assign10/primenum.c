/*
      Name: Matthew Matze
      Date: 10/23/2013
      Class: CSC1710
      Location:~/csc1710/assign10
*/

#include<stdio.h>
#include<stdbool.h>

   int main(void)
{
   bool p[500];
   int n,j,i,count=0;
   fscanf(stdin, "%d", &n);
   
   for(i=2;i<=n;i++)
      p[i]=true;
   p[1]=false;
   i=2;
   while(i<=n)
   {
      if (p[i]==true)
      {
         for(j=2; j*i<=n;j++)
            p[i*j]=false;
      }
      i++;
   }
   for(i=2;i<n;i++)
   {
      if(p[i]==true)
      {
      fprintf(stdout, "   %3d",i);
      count++;
         if(count%5==0&&count!=0)
         {
         fprintf(stdout, "\n");
         } 
      }
   }
   fprintf(stdout, "\n");
return 0;
}
