//Programmer: Justin Reini  Date: 03/31/2020
//File: filestrm.cpp  Class: Lab 301
/*Description: This file contains the function definitions for the 
cylinder volume program*/

#include "cylinder.h"
#include <iostream>
using std::cout;
using std::cin;

int cylinder::getrad()
{
  int rad;
  cout<<"Enter the radius of the cylinder: ";
  cin>>rad;
  return rad;
}

int cylinder::getht()
{
  int ht;
  cout<<"Enter the height of the cylinder: ";
  cin>>ht;
  return ht;
}

void cylinder::setrad(const int rad)
{
    m_rad = rad;
    return;
}

void cylinder::setht(const int ht)
{
    m_ht = ht;
    return;
}

void cylinder::calc_vol()
{
  float vol;
  vol=(m_rad*m_rad)*m_ht*PI;
  cout<<endl;
  cout<<"The volume of the cylinder is: "<<vol<<endl;
  cout<<"Have a good day!"<<endl<<endl;
  return;
}
