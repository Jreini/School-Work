//Programmer: Justin Reini  Date: 03/10/2020
//File: sort.h  Class: Lab 301
/*Description: This file contains prototypes for functions used in the 
bubble sort program*/

#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int ARRAY_SIZE=10;
const float ARRAY_TWO_MAX=1000.0;

//Pre for template: The = and > operators must be defined for type T
//Description: the num_swap() function swaps two numbers in the array
//Pre: None
//Post: The two numbers are swapped
template <typename T>
void num_swap(T & t1, T & t2)
{
  T t3=t1;
  t1=t2;
  t2=t3;
  return;
}
//Description: the bub_sort() function sorts an array from smallest to largest
//Pre: Must have an array full of numbers
//Post: The array is sorted from smallest to largest
template <typename T>
void bub_sort(T array[], const int ARRAY_SIZE)
{
  for(int i=0;i<ARRAY_SIZE;i++)
    for(int j=0;j<ARRAY_SIZE-1;j++)
    {
      if (array[j]>array[j+1])
        num_swap(array[j],array[j+1]);
    }
  return;
}
//Description: the print_array() function prints the array to the screen
//Pre: Must have an array full of numbers
//Post: The array is outputed to the screen
template <typename T>
void print_array(T array[],const int ARRAY_SIZE)
{
  for(int i=0;i<ARRAY_SIZE;i++)
    cout<<array[i]<<"  ";
  cout<<endl;
  return;
}
/*Description: the fill_array1() function fills the first array with
random integers*/
//Pre: Array Size must be larger than 0
//Post: The array is filled with random integers
void fill_array1(int array_one[],const int ARRAY_SIZE);

/*Description: the fill_array2() function fills the second array with
random floats*/
//Pre: Array Size must be larger than 0
//Post: The array is filled with random floats
void fill_array2(float array_two[],const int ARRAY_SIZE);

#endif