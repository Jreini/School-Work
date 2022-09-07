//Programmer: Justin Reini  Date: 03/17/2020
//File: filestrm.cpp  Class: Lab 301
/*Description: This file contains the function definitions for the 
file stream program*/
#include "filestrm.h"

void avg(int num_array[],float avg_array[],const int NUM_ARRAY_SIZE)
{
  avg_array[0]=0;
  for(int i=1; i<NUM_ARRAY_SIZE; i++)
  {
    avg_array[i]=((num_array[i])-(num_array[i-1]))/2;
  }
  return;
}
void num_swap(float & num1, float & num2)
{
  float num3=num1;
  num1=num2;
  num2=num3;
  return;
}
void bub_sort(float avg_array[], const int NUM_ARRAY_SIZE)
{
  for(int i=0;i<NUM_ARRAY_SIZE;i++)
    for(int j=0;j<NUM_ARRAY_SIZE-1;j++)
    {
      if (avg_array[j]>avg_array[j+1])
        num_swap(avg_array[j],avg_array[j+1]);
    }
  return;
}
float med(float avg_array[])
{
  float median;
  median=((avg_array[4])+(avg_array[5]))/2;
  return median;
}
float mode(float avg_array[],const int NUM_ARRAY_SIZE)
{
  int count=1;
  int occurances=1;
  int curr_mode=avg_array[0];
  int mode=curr_mode;
  for (int i=1; i<NUM_ARRAY_SIZE; i++) 
  {
    if (avg_array[i]==curr_mode)
      ++count;
    else 
    {
      if (count>occurances)
      {
        occurances=count;
        mode=curr_mode;
      }
      count=1;
      curr_mode=avg_array[i];
    }
  } 
  return mode;
}
