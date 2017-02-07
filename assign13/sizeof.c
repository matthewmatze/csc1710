#include<stdio.h>

   int main(void)
{
   int X[][]={{22,7,13,65},{15,6,78,11},{3,65,9,12}};
   int i,j;

   i=2;
   for(j=0;j<4;j++)
	if(X[i][j]>10)
		printf("%4d %4d\n", i ,j);

   return(0);
}
