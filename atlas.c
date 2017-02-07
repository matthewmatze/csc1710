#include<stdio.h>

int main(void){

int i,j,x,y;
int z=1;
int array[30][30];
char test;
char nlc;

x=y=0;
	fscanf(stdin, "%i", &x);
while(x!=-1){
		y=0;
		fscanf(stdin, "%c%i",&nlc, &y);
		fscanf(stdin, "%c",&nlc);
	for(i=0;i<x;i++){	
		for(j=0;j<y;j++){
			fscanf(stdin, "%c",&test);
			if(test!='X'){
				array[j][i]=z;
				z++;
			} else {
				array[j][i]=1234;
			}
		}
		fscanf(stdin, "%c",&nlc);
	}

	z=1;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(array[j][i]!=1234){
			fprintf(stdout, "%i ", (z));
			if(i-1>=0&&array[j][i-1]!=1234)
			fprintf(stdout, "%i ", array[j][i-1]);
			else
			fprintf(stdout, "0 ");
			if(j+1<=x&&array[j+1][i]!=1234)
			fprintf(stdout, "%i ", array[j+1][i]);
			else
			fprintf(stdout, "0 ");
			if(i+1<=x&&array[j][i+1]!=1234)
			fprintf(stdout, "%i ", array[j][i+1]);
			else
			fprintf(stdout, "0 ");
			if(j-1>=0&&array[j-1][i]!=1234)
			fprintf(stdout, "%i ", array[j-1][i]);
			else
			fprintf(stdout, "0 ");
		fprintf(stdout, "\n");
		z++;}
		}
	}	
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			array[j][i]=1234;
		}
	}
	fprintf(stdout, "\n");
	x=0;
	z=1;
	fscanf(stdin, "%i",&x);
}
return 0;
}
