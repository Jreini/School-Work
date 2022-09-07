//Programmer: Justin Reini  Date: 05/5/2020
//File: main.cpp  Class: Lab 301
/*Description: Main file for the array program*/
#include "array.h"

int main()
{
  myArray arr1,arr2(10);
  arr2=9;
  printf(arr2);
  arr1=arr2;
  printf(arr1);
  myArray arr3(arr1);
  printf(arr3);
  return 0;
}