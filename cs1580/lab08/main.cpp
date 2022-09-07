//Programmer: Justin Reini  Date: 03/10/2020
//File: main.cpp  Class: Lab 301
//Description: Main file for the bubble sort program
#include "sort.h"
int main()
{
  srand(time(NULL));  //Rand num generator
  int array_one[ARRAY_SIZE];
  float array_two[ARRAY_SIZE];
  fill_array1(array_one,ARRAY_SIZE);
  print_array(array_one,ARRAY_SIZE);
  bub_sort(array_one,ARRAY_SIZE);
  print_array(array_one,ARRAY_SIZE);

  fill_array2(array_two,ARRAY_SIZE);
  print_array(array_two,ARRAY_SIZE);
  bub_sort(array_two,ARRAY_SIZE);
  print_array(array_two,ARRAY_SIZE);
  return 0;
}