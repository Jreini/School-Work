//Programmer: Justin Reini  Date: 03/17/2020
//File: main.cpp  Class: Lab 301
//Description: Main file for the file stream program
#include "filestrm.h"
int main()
{
  const int NUM_ARRAY_SIZE=10;
  int num_array[NUM_ARRAY_SIZE];
  float avg_array[NUM_ARRAY_SIZE];
  float median;
  float most;
  ifstream in;
  ofstream out;
  in.open("input.txt");
  out.open("output.txt");
  for(int i=0; i<NUM_ARRAY_SIZE;i++)
  {
    in>>num_array[i];
  }
  in.close();
  avg(num_array,avg_array,NUM_ARRAY_SIZE);
  bub_sort(avg_array,NUM_ARRAY_SIZE);
  median=med(avg_array);
  most=mode(avg_array,NUM_ARRAY_SIZE);
  for(int i=0; i<NUM_ARRAY_SIZE;i++)
  {
    out<<avg_array[i]<<" ";
  }
  out<<endl;
  out<<median<<" "<<most;
  out.close();
  return 0;
}