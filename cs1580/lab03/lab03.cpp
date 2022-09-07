//Programmer: Justin Reini  Date: 02/04/2020
//File: Lab03.cpp  Class: Lab 301
//Description: Slope Calculation

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int num1;  //First number-Input Variable
  int num2;  //Second number-Input Variable
  int num3;  //Third number-Input Variable
  int num4;  //Fourth number-Input Variable
  float slope;  //Slope-Output Variable
  const float SQUARE_ROOT=(0.5);  //Square root constant
  
  //Welcome message
  cout<<"Hello and welcome to the Slope Calculator."<<endl;
  cout<<"Please input four integers"<<endl<<endl;

  //Assigning variables to inputs
  cout<<"Input 1:"<<endl;
  cin>>num1;
  cout<<"Input 2:"<<endl;
  cin>>num2;
  cout<<"Input 3:"<<endl;
  cin>>num3;
  cout<<"Input 4:"<<endl;
  cin>>num4;

  //Calculations
  slope=static_cast<int>(pow((static_cast<float>(num1+num2)/num3),SQUARE_ROOT))
  %num4;

  //Output
  cout<<"The output of the equation is:"<<endl;     
  cout<<slope<<endl;

  return 0;
}
