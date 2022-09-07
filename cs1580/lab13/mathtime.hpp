//Programmer: Justin Reini  Date: 04/21/2020
//File: mathtime.hpp  Class: Lab 301
//Description: Function definitions for the mathtime program

#include "mathtime.h"
#include <iostream>
using std::cout;
using std::cin;

template<class T>
void MathWiz<T>::setnum1(const T num1)
{
  m_firstnum = num1;
  return;
}

template<class T>
void MathWiz<T>::setnum2(const T num2)
{
  m_secondnum = num2;
  return;
}

template<class T>
MathWiz<T>::MathWiz(const T num1, const T num2)
{
  setnum1(num1);
  setnum2(num2);
}

