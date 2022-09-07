//Programmer: Justin Reini  Date: 03/31/2020
//File: filestrm.h  Class: Lab 301
/*Description: This file contains prototypes for functions used in the 
cylinder volume program*/

#ifndef CYLINDER_H
#define CYLINDER_H

#include <iostream>
using namespace std;

//Global Constants
const float PI=3.14;


//cylinder Class
/*This class is used to store the radius and height of a
cylinder and find its volume*/

/*Description: The getrad() function asks for user input for the radius
and returns it*/
//Pre: None
//Post: The radius is returned to main

/*Description: The getht() function asks for user input for the height
and returns it*/
//Pre: None
//Post: The height is returned to main

/*Description: The setrad() function sets the radius to the
cylinder member variable for radius*/
//Pre: The radius must be passed in
//Post: The radius is set to the member variable for radius

/*Description: The setht() function sets the height to the
cylinder member variable for height*/
//Pre: The height must be passed in
//Post: The height is set to the member variable for height

/*Description: The calc_vol() function uses the member variables 
of cylinder to calculate the volume of the cylinder 
and then print it out to the screen*/
//Pre: None
//Post: The volume is calculated then printed to the screen

class cylinder
{
  public:
    int getrad();       
    int getht();       
    void setrad(const int rad);
    void setht(const int ht);
    void calc_vol();
  private:
    int m_rad;
    int m_ht;
};

#endif