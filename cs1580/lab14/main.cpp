//Programmer: Justin Reini  Date: 04/28/2020
//File: main.cpp  Class: Lab 301
/*Description: Main file for the point program*/
#include "point.h"

int main()
{
  srand(time(NULL));  //Rand num generator
  cout<<endl;
  point * ptr = new point[10];  //New pointer array
  for(int i=0;i<10;i++)  //Loop through array
  {
    ptr->print(ptr[i],i);  //pass the point and what number it is
  }
  delete [] ptr;  //deletion of the pointer
  ptr=NULL;
  return 0;
}