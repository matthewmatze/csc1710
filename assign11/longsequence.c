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

/* int load (int numberofelements)
 *
 *Precondition:
 *   Input integer will be loaded with an int containing the number of elements in the data set
 *Postcondition:
 *   This will load an array with a maximum of 100 elements with the number of elements specified.
 */
int * load(int dataset[], int numberOfElements);
/* int findlongestprint(int dataset[],int numberOfElements, int dataSetNumber)
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

void findlongestprint(int dataSetNumber, int dataset[], int numberOfElements);


int main (void)
{
   int numberOfElements,dataset[100];
   int dataSetNumber=1;
   fscanf(stdin, "%i", &numberOfElements);

   while(numberOfElements!=-1){
      load(dataset, numberOfElements);
      findlongestprint(dataSetNumber, dataset, numberOfElements);
      printf("\n");
      dataSetNumber++;
      fscanf(stdin, "%i", &numberOfElements);
   }
   return 0;
}

void findlongestprint(int dataSetNumber, int dataset[], int numberOfElements)
{
   int i, cnt, locEnd, locStart, longlength,longLocStart,longLocEnd;

   longLocStart=longLocEnd=locStart=locEnd=longlength=0;
   cnt=1;
   for(i=0;i<numberOfElements;i++){
      if(dataset[i]<dataset[i+1]){
         cnt++;
         locEnd++;
      } else {
         if(longlength<cnt){
            longlength=cnt;
            longLocStart=locStart;
            longLocEnd=locEnd;
         }
         cnt=1;
         locStart=i+1;
         locEnd=i+1;
      }
   }
   if(numberOfElements!=0&&longlength==0){
      longlength=numberOfElements;
      longLocEnd=numberOfElements-1;
   }
   printf("Data Set %i ==> Longest: %i Positions: %i-%i Sequence: ",dataSetNumber, longlength, longLocStart, longLocEnd);
   for(i=longLocStart;i<=longLocEnd;i++){
      printf("%i ",dataset[i]);
   }
}

int * load(int dataset[], int numberOfElements)
{
   int i;
   for(i=0;i<numberOfElements;i++)
      fscanf(stdin, "%i",&dataset[i]); 
   return dataset;
} 
