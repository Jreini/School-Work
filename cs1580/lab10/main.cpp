//Programmer: Justin Reini  Date: 03/31/2020
//File: main.cpp  Class: Lab 301
//Description: Main file for the cylinder volume program

#include "cylinder.h"
int main()
{
  int rad;
  int ht;
  cylinder f;
  rad=f.getrad();
  ht=f.getht();
  f.setrad(rad);
  f.setht(ht);
  f.calc_vol();
  return 0;
}
