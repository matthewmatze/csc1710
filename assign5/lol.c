#include<stdio.h>

   int main(void)
{
   char classname[20];
   double avg;
   int cnt;
   int i;
   int x, z;
	printf("please type a class name and then number of students");
   scanf("%[^\n]",classname);
   scanf("%d", &cnt);
   z=0;
   for(i=0; i<cnt; i++){
      scanf("%d",&x);
      z+=x;
   }
   avg=(double)z/cnt;
   printf("%s   avg=%0.2lf/n",classname, avg );

   return 0;
}
