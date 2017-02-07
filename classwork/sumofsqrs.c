#include<stdio.h>

   main(void)
{
   int i,n,x,sum;
scanf("%d",n);
for(i=0;i<n;i++)
{
   scanf("%d ",&x);
   sum+=x*x;
}
printf("Sum of squares=%d", sum);
return 0;

}
