//Programmer: Justin Reini  Date: 04/21/2020
//File: main.cpp  Class: Lab 301
//Description: Main file for the math time program

#include "mathtime.h"
#include "mathtime.hpp"
int main()
{
  int num1;
  int num2;
  float num3;
  float num4;
  cout<<"Enter an integer: "<<endl;
  cin>>num1;
  cout<<"Enter a second integer: "<<endl;
  cin>>num2;
  cout<<"Enter a float: "<<endl;
  cin>>num3;
  cout<<"Enter a second float: "<<endl;
  cin>>num4;
  MathWiz<int> f(num1,num2);
  MathWiz<float> g(num3,num4);
  cout<<endl;
  cout<<"For the integers:";
  cout<<endl;
  cout<<f;
  cout<<"For the floats:";
  cout<<endl;
  cout<<g;
  return 0;
}