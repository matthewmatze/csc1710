#include <stdio.h>

int load(int y[])
{
   int cnt=0;
   while(scanf("%d",&y[cnt])!=EOF)
   cnt++;
   return cnt;
}

void bubblesort(int x[], int n)
{
   int i,j;
   int temp;
   for(i=0;i<n-1;i++)
      for(j=0;j<n-i;j++){
         if(x[j]<x[j+1])
            temp=x[j];
            x[j]=x[j+1];
            x[j+1]=temp;
         }
}

void print(int x[], int n)
{
   int i;
   int cb=90;
   for(i=0;i<n;i++){
      if(x[i]>=cb){
         if(cb<=50){
            x[i]=0;
            }
      printf("%d ",x[i]);
      }
      else{
         if(cb<=50)
            x[i]=0;
         printf("\n%d ",x[i]);
         cb=cb-10;
      }
   }
}

int main(void)
{

   int x[100],n;
   n=load(x);
   bubblesort(x,n);
   print(x,n);

   return 0;

}
