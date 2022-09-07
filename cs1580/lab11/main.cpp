//Programmer: Justin Reini  Date: 04/7/2020
//File: main.cpp  Class: Lab 301
//Description: Main file for the cylinder volume program

#include "cylinder.h"
int main()
{
  float rad;
  float ht;
  cout<<"Enter the radius of the cylinder: ";
  cin>>rad;
  cout<<endl;
  cout<<"Enter the height of the cylinder: ";
  cin>>ht;
  cout<<endl;
  cout<<endl;
  cylinder f,g(rad,ht),h;
  h=f+g;
  cout<<"First cylinder:"<<endl;
  cout<<endl;
  f.print();
  cout<<"Second cylinder:"<<endl;
  cout<<endl;
  g.print();
  cout<<"Third cylinder:"<<endl;
  cout<<endl;
  h.print();
  return 0;
}
