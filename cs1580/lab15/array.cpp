//Programmer: Justin Reini  Date: 05/5/2020
//File: array.cpp  Class: Lab 301
/*Description: Function definitions for the
array program*/
#include "array.h"

myArray::myArray(const myArray& source) : m_size(source.m_size)
{
  m_data= new float[m_size];
  for(int i=0; i<m_size;i++)		
    m_data[i]=source.m_data[i];	
  cout<<"Copy constructor called"<<endl;
}		   

myArray& myArray::operator=(const myArray& source)
{
  if(m_data!=source.m_data)	
  {
    m_size=source.m_size;	
    delete [] m_data;		
    m_data= new float[m_size];	
    for (int i=0; i<m_size;i++)	
      m_data[i]=source.m_data[i];
  }
  cout<<"Copy assignment operator called"<<endl;
  return *this;
}

myArray& myArray::operator=(const int num)
{
  for(int i=0;i<m_size;i++)
  {
    m_data[i]=num;
  }
  return *this;
}