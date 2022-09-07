//Programmer: Justin Reini  Date: 03/10/2020
//File: sort.cpp  Class: Lab 301
/*Description: This file contains the function definitions for the 
bubble sort program*/
#include "sort.h"
void fill_array1(int array_one[],const int ARRAY_SIZE)
{
  for(int i=0; i<ARRAY_SIZE; i++)
    array_one[i]=0+rand()%(1000-0+1);
  return;
}
void fill_array2(float array_two[],const int ARRAY_SIZE)
{
  for(int i=0; i<ARRAY_SIZE; i++)
    array_two[i]=rand()/(static_cast<float>(RAND_MAX/ARRAY_TWO_MAX));
  return;
}
