//Programmer: Justin Reini  Date: 03/17/2020
//File: filestrm.h  Class: Lab 301
/*Description: This file contains prototypes for functions used in the 
file stream program*/

#ifndef FILESTRM_H
#define FILESTRM_H

#include <iostream>
#include <fstream>
using namespace std;

//Global constants
const int NUM_ARRAY_SIZE=10;

//Function declarations
/*Description: The avg() function will take in the array of numbers
and find the average between each number and the number before it
and store those numbers in a new array*/
//Pre: An array full of numbers must be passed in
//Post: The avg_array is filled 
void avg(int num_array[],float avg_array[],const int NUM_ARRAY_SIZE);

//Description: the num_swap() function swaps two numbers in the array
//Pre: None
//Post: The two numbers are swapped
void num_swap(float & num1, float & num2);

//Description: the bub_sort() function sorts an array from smallest to largest
//Pre: Must have an array full of numbers
//Post: The array is sorted from smallest to largest
void bub_sort(float avg_array[], const int NUM_ARRAY_SIZE);

/*Description: The med() function will take in the array of averages
and find the median and return it*/
//Pre: An array full of averages must be passed in
//Post: The median is found and returned
float med(float avg_array[]);

/*Description: The mode() function will take in the array of averages
and find the mode and return it*/
//Pre: An array full of averages must be passed in
//Post: The mode is found and returned
float mode(float avg_array[],const int NUM_ARRAY_SIZE);

#endif