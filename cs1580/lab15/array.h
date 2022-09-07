//Programmer: Justin Reini  Date: 05/5/2020
//File: array.h  Class: Lab 301
/*Description: Class and Function declarations for the
array program*/
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

//myArray Class
/*This class is used to create arrays*/

/*Description: The myArray() function constructs an array object, setting the
size to what is passed in and creating a new array using the size*/
//Pre: size must be passed in
//Post: The size and an array initialized

/*Description: The myArray() function constructs a default array object, 
defaulting size to 0 and data to a null pointer*/
//Pre: None
//Post: The size and data are initialized

/*Description: The myArray() copy function takes in an array and constructs a
copy of that array object*/
//Pre: a myArray object must be passed in
//Post: the array is copied

/*Description: The ~myArray() destructor function deletes the pointer data
in the myArray object*/
//Pre: None
//Post: the data is deleted

/*Description: The first operator=() overloads the = operator in order to copy
one object into another*/
//Pre: A pre-filled myArray object must be passed in
//Post: The = operator is overloaded to allow an object to be copied

/*Description: The second operator=() overloads the = operator in order to set
all of the elements of the myArray object to one number*/
//Pre: A positive integer must be passed in
/*Post: The = operator is overloaded to allow the elements 
of the array to be changed to one number*/

/*Description: The printf() takes in an array and loops through it, printing
out each element and then it returns nothing*/
//Pre: A pre-filled myArray object must be passed in
//Post: The array is printed to the screen,element by element

class myArray
{
  public:
    myArray(const int size): m_size(size),m_data(new float[size]){}
    myArray(): m_size(0),m_data(nullptr){}
    myArray(const myArray& source);
    ~ myArray() 
    {
      delete [] m_data;
      cout<<"Destructor called"<<endl;
    }
    myArray& operator=(const myArray& source);
    myArray& operator=(const int num);
    friend void printf(const myArray & arr)
    {
      for(int i=0;i<arr.m_size;i++)
      {
        cout<<arr.m_data[i]<<endl;
      }
      return;
    }
  private:
    int m_size;
    float * m_data;
};
#endif