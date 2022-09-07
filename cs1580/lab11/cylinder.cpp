//Programmer: Justin Reini  Date: 04/7/2020
//File: cylinder.cpp  Class: Lab 301
/*Description: This file contains the function definitions for the 
cylinder volume program*/

#include "cylinder.h"
#include <iostream>
using std::cout;
using std::cin;


void cylinder::setrad(const float rad)
{
    m_rad = rad;
    return;
}

void cylinder::setht(const float ht)
{
    m_ht = ht;
    return;
}

cylinder::cylinder(const float rad, const float ht)
{
  setrad(rad);
  setht(ht);
  m_vol=(m_rad*m_rad)*m_ht*PI;
}

cylinder::cylinder()
{
  m_rad=7.5;
  m_ht=11.435;
  m_vol=(m_rad*m_rad)*m_ht*PI;
}

cylinder operator+(const cylinder & lhs, const cylinder & rhs)
{
  cylinder result(lhs);
  return(result+=rhs);
}

cylinder& cylinder::operator+=(const cylinder & rhs)
{
  m_rad+=rhs.m_rad;
  m_ht+=rhs.m_ht;
  m_vol=(m_rad*m_rad)*m_ht*PI;
  return (*this);
}

void cylinder::print()
{
  cout<<"Radius: "<<m_rad<<endl;
  cout<<"Height: "<<m_ht<<endl;
  cout<<"Volume: "<<m_vol<<endl;
  cout<<endl;
  return;
}