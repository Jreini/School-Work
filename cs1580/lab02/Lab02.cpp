//Programmer: Justin Reini  Date: 01/28/2020
//File: Lab02.cpp  Class: Lab 301
//Description: Lab 2

#include <iostream>
using namespace std;

int main()
{
  //Variable declaration
  int input_1;  //First number 
  int input_2;  //Second number
  int solution; //Solution
  
  cout<<"Welcome to the math basic tutorial"<<endl;
  cout<<"Please input two numbers"<<endl;

  cin>>input_1;  //Takes first number
  cin>>input_2;  //Takes second number

  //Adds the inputs 
  solution = input_1 + input_2;
  //Outputs solution of the addition 
  cout<<"Adding the two numbers results in: "<<solution<<endl;
  //Subracts the inputs
  solution = input_1 - input_2; 
  //Outputs solution of the subtraction
  cout<<"Subtracting input 2 from input 1 results in: "<<solution<<endl;
  //Multiplies the inputs 
  solution = input_1 * input_2;
  //Outputs solution of the multiplication
  cout<<"Multiplying the two numbers together results in: "<<solution<<endl;
  //Divides the inputs
  solution = input_1/input_2;
  //Outputs solution of the division
  cout<<"Dividing number 1 by number 2 results in: "<<solution<<endl;

  return 0;

}
