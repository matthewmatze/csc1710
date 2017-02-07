/* 
 * Name: Matthew Matze
 * Class: CSC-1710
 * Date: 11-6-13
 * location: ~/csc1710/assign11
 *
 * This program will find the longest sequence of consecutive integers in each data set.
 * Then output the ammount of positions in the longest sequence, the sequence's location
 * , and then state the numbers in the sequence.
*/


#include<stdio.h>

int * load(int dataset[], int numberOfElements);
/* int load (int numberofelements)
 *
 *Precondition:
 *   Input integer will be loaded with an int containing the number of elements in the data set
 *Postcondition:
 *   This will load an array with a maximum of 100 elements with the number of elements specified.
 */

void findlongest(int *longLengthptr,int *longLocStartptr, int *longLocEndptr, int dataset[], int numberOfElements);
/* int findlongest(int dataset[],int numberOfElements, int dataSetNumber)
 *
 * Precondition:
 *    The input integer array will have been loaded with the number of elements designated by the user.
 *    The input integer numberofelements will designate how many elements are in the dataset
 *    The input integer datasetnumber will designate which dataset it is on
 * Postcondition:
 *    The Output will have no changes.
 * The function will find the longest consecutive sequence and output to screen how many positions are
 * in the sequence, where the sequence is, and the numbers in the sequence.
 */

void print(int dataSetNumber, int longLength, int longLocStart, int longLocEnd, int dataset[]);

/*void print(int int int
 *
 * Precondition:
 *    The input will be the ammount of positions in the longest sequence, which dataset it is, where 
 *    the dataset is located in the sequence and the longest consecutive sequnce of integers in the dataset.
 *Postcondition:
 *    It will output nothing
 *The function will print to the screen which data set it is, the lenth of the longest consecutive sequence in the data
 *set, the location of the sequence in the data set, and then the sequence itself.
*/ 

int main (void)
{
   int numberOfElements,dataset[100],longLength, longLocStart, longLocEnd;
   int dataSetNumber=1;
   fscanf(stdin, "%i", &numberOfElements);

   while(numberOfElements!=-1){
      load(dataset, numberOfElements);
      findlongest(&longLength, &longLocStart, &longLocEnd, dataset, numberOfElements);
      print(dataSetNumber, longLength, longLocStart, longLocEnd,dataset);
      printf("\n");
      dataSetNumber++;
      fscanf(stdin, "%i", &numberOfElements);
   }
   return 0;
}

void findlongest(int *longLengthptr,int *longLocStartptr, int *longLocEndptr, int dataset[], int numberOfElements)
{
   int i, cnt, locEnd, locStart;

   *longLocStartptr=*longLocEndptr=locStart=locEnd=*longLengthptr=0;
   cnt=1;
   
   for(i=0;i<numberOfElements;i++){
      if(dataset[i]<dataset[i+1]){
         cnt++;
         locEnd++;
      } else {
         if(*longLengthptr<cnt){
            *longLengthptr=cnt;
            *longLocStartptr=locStart;
            *longLocEndptr=locEnd;
         }
         cnt=1;
         locStart=i+1;
         locEnd=i+1;
      }
   }
   if(numberOfElements!=0&&*longLengthptr==0){
      *longLengthptr=numberOfElements;
      *longLocEndptr=numberOfElements-1;
   }
}

int * load(int dataset[], int numberOfElements)
{
   int i;
   for(i=0;i<numberOfElements;i++)
      fscanf(stdin, "%i",&dataset[i]); 
   return dataset;
} 
void print(int dataSetNumber, int longLength, int longLocStart, int longLocEnd, int dataset[])
{
   int i;
   printf("Data Set %i ==> Longest: %i Positions: %i-%i Sequence: ",dataSetNumber, longLength, longLocStart, longLocEnd);
   for(i=longLocStart;i<=longLocEnd;i++){
      printf("%i ",dataset[i]);
   }
}
