//Programmer: Justin Reini  Date: 04/7/2020
//File: cylinder.h  Class: Lab 301
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

/*Description: The setrad() function sets the radius to the
cylinder member variable for radius*/
//Pre: The radius must be passed in
//Post: The radius is set to the member variable for radius

/*Description: The setht() function sets the height to the
cylinder member variable for height*/
//Pre: The height must be passed in
//Post: The height is set to the member variable for height

/*Description: The print() function uses the member variables 
of cylinder and prints them out to the screen*/
//Pre: None
//Post: The radius, height and volume are printed to the screen

/*Description: The default cylinder() function sets the values of the radius
and the height to known numbers and calculates the volume*/
//Pre: None
//Post: The volume is calculated and stored in a member variable

/*Description: The cylinder() function (with arguments) sets the values of the 
radius and the height to the class member variables and calculates the volume*/
//Pre: Radius and Height must be passed in
//Post: The volume is calculated and stored in a member variable

/*Description: The operator+() function takes in two cylinders and
defines the + operator in order to add the radius of each cylinder together
as well as the height in the += operator function*/
//Pre: Two cylinders must be passed in
//Post: A new cylinder is created and returned

/*Description: The operator+=() function takes in the second cylinder and
defines the += operator in order to add the radius of each cylinder together
as well as the height and then finds the volume of the added variables*/
//Pre: The second cylinder must be passed in
/*Post: The new cylinder's values have been calculated, stored in
member variables and returned*/
class cylinder
{
  public:
    void setrad(const float rad);
    void setht(const float ht);
    void print();
    cylinder();
    cylinder(const float rad, const float ht);
    friend cylinder operator+(const cylinder & lhs, const cylinder & rhs);
    cylinder& operator+=(const cylinder & rhs);
  private:
    float m_rad;
    float m_ht;
    float m_vol;
};

#endif