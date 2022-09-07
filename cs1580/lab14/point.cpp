//Programmer: Justin Reini  Date: 04/28/2020
//File: point.cpp  Class: Lab 301
/*Description: Function definitions for the
point program*/
#include "point.h"

point::point()  //default constructor initializing member variables
{
  m_X=0+rand()%(20-0+1);
  m_Y=0+rand()%(20-0+1);
}

void point::print(const point & p, const int i)  //printing each point
{
  cout<<"Point "<<i<<" is at ("<<p.m_X<<
  ","<<p.m_Y<<")"<<endl;
}