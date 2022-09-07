//Programmer: Justin Reini  Date: 04/28/2020
//File: point.h  Class: Lab 301
/*Description: Struct and Function declarations for the
point program*/
#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//struct point
/*This struct is used to get a random point and print it to the user*/

/*Description: The point() function takes in nothing
and constructs a point by picking a random number from 0 to 20
for x and then repeating the process for y*/
//Pre: None
//Post: the point is set up

/*Description: The print() function takes in a point as well as an int
and outputs the point and its location in a clean format*/
//Pre: A point must be passed as well as it's location
//Post: The point and it's location is printed to the screen

struct point
{
  int m_X;
  int m_Y;
  point();
  void print(const point & p, const int i);
};


#endif