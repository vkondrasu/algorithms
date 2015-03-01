/*
   Code to do multiplication of two integers, without using the "*" operator.
   TO-DO: Is there any solution that is optimal than the one we implemented here? If so, code that.
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

using namespace std;

char *decimal_to_binary(int n)
{
   int c, d, count;
   char *pointer;
 
   count = 0;
   pointer = (char*)malloc(32+1);
 
   if ( pointer == NULL )
      exit(EXIT_FAILURE);
 
   for ( c = 31 ; c >= 0 ; c-- )
   {
      d = n >> c;
 
      if ( d & 1 )
         *(pointer+count) = 1 + '0';
      else
         *(pointer+count) = 0 + '0';
 
      count++;
   }
   *(pointer+count) = '\0';
 
   return  pointer;
}


void fillArray(int*sumarray, int small)
{
}


int multiply(int a, int b)
{
  int small = MIN(a,b);
  int big = MAX(a,b);
  int arSize = log(small)/log(2) + 1;
  int *array = (int*)malloc(sizeof(int)*arSize);
  memset(array, 0, sizeof(int)*arSize);
  int *sumarray = (int*)malloc(sizeof(int)*arSize);
  memset(sumarray, 0, sizeof(int)*arSize);
  char* binaryArray = decimal_to_binary(small);
  sumarray[0] = big;
  int prev = big;
  for(int i= 1; i<arSize; i++)
  {
    sumarray[i] = prev + prev;
    prev = sumarray[i];
  }
  int result = 0;
  for(int i = strlen(binaryArray) -1; i >=  (strlen(binaryArray) - arSize); i--)
  {
    if(binaryArray[i] == '1'){
      result += sumarray[strlen(binaryArray) - i-1]; }
  }
  return result;
}
int main(int argc, char* argv[])
{
  cout<<multiply(atoi(argv[1]), atoi(argv[2]))<<endl;
  return 0;
}
