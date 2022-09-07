//Programmer: Justin Reini  Date: 04/21/2020
//File: mathtime.h  Class: Lab 301
/*Description: Classes and Function declarations for the
mathtime program*/

#ifndef MATHTIME_H
#define MATHTIME_H

#include <iostream>
#include <ostream>
using namespace std;

//MathWiz Class
/*This class is used to perform math calculations with different types of
inputs*/

/*Description: The setnum1() function takes in a T and sets 
num1 to the member variable for number1*/
//Pre: a positive number must be passed in
//Post: the member variable for num1 is set

/*Description: The setnum2() function takes in a T and sets 
num2 to the member variable for number2*/
//Pre: a positive number must be passed in
//Post: the member variable for num2 is set

/*Description: The getnum1() function returns the member variable
for the first number*/
//Pre: None
//Post: The member variable for the first number is returned

/*Description: The getnum2() function returns the member variable
for the second number*/
//Pre: None
//Post: The member variable for the second number is returned

/*Description: The MathWiz() function takes in two numbers
and constructs a MathWiz object*/
//Pre: Two numbers must be passed in
//Post: a MathWiz object is set up

/*Description: The operator+() function takes in a MathWiz object and its
member variables and defines the + operator in order to 
add the member variables together to get a sum*/
//Pre: The Mathwiz object must be passed in
/*Post: The sum is returned*/

/*Description: The operator-() function takes in a MathWiz object and its
member variables and defines the - operator in order to 
subtract the member variables from each other to get a difference*/
//Pre: The Mathwiz object must be passed in
/*Post: The difference is returned*/

/*Description: The operator/() function takes in a MathWiz object and its
member variables and defines the / operator to divide the first 
number by the second in order to get the difference*/
//Pre: The Mathwiz object must be passed in
/*Post: The difference is returned*/

/*Description: The operator*() function takes in a MathWiz object and its
member variables and defines the * operator to multiply the member variables
together to get a product*/
//Pre: The Mathwiz object must be passed in
/*Post: The product is returned*/

/*Description: The operator<<() function takes in the a Mathwiz object
and its member variables and defines the << operator in order to print
the results of each operation to the screen*/
//Pre: The Mathwiz object must be passed in
/*Post: The Mathwiz operations are returned and printed to the user's screen*/
template <class T>
template <class U>
class MathWiz
{
  public:
    void setnum1(const T num1);
    void setnum2(const T num2);
    T getnum1() const {return m_firstnum;}
    T getnum2() const {return m_secondnum;}
    MathWiz(const T num1, const T num2);
    MathWiz<T> operator+(const MathWiz<T> & mat)
    {
      T sum;
      sum=mat.getnum1()+mat.getnum2();
      return MathWiz<T>(sum);
    }
    MathWiz<T> operator-(const MathWiz<T> & mat)
    {
      T dif;
      dif=mat.getnum1()-mat.getnum2();
      return MathWiz<T>(dif);
    }
    MathWiz<T> operator/(const MathWiz<T> & mat)
    {
      T div;
      div=mat.getnum1()/mat.getnum2();
      return MathWiz<T>(div);
    }
    MathWiz operator*(const MathWiz<T> & mat)
    {
      T product;
      product=mat.getnum1()*mat.getnum2();
      return MathWiz<T>(product);
    }
    friend ostream& operator <<(ostream & out, const MathWiz<U> & mat)
    {
      out<<"Sum: "<< mat.operator+(mat) <<endl
      <<"Difference: "<< mat.operator-(mat) <<endl
      <<"Multiplied: "<< mat.operator*(mat) <<endl
      <<"Divided: "<< mat.operator/(mat) <<endl<<endl;
      return out;
    }
  private:
    T m_firstnum;
    T m_secondnum;
};

#endif