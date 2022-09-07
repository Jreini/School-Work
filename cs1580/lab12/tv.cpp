//Programmer: Justin Reini  Date: 04/14/2020
//File: tv.cpp  Class: Lab 301
/*Description: This file contains the function definitions for the 
tv program*/

#include "tv.h"
#include <iostream>
using std::cout;
using std::cin;


void tv_show::setname(const string name)
{
  m_Name=name;
  return;
}

string tv_show::getname()
{
  return m_Name;
}

void tv_show::setStation(const string station)
{
  m_Station=station;
  return;
}

string tv_show::getStation()
{
  return m_Station;
}

void movie::setname(const string name)
{
  m_Name=name;
  return;
}

string movie::getname()
{
  return m_Name;
}

void movie::setTheater(const string theater)
{
  m_Theater=theater;
  return;
}

string movie::getTheater()
{
  return m_Theater;
}

ostream& operator <<(ostream & out, const tv_show & tv)
{
  out<<"TV show "<< tv.m_Name<<" is on the "
  <<tv.m_Station<<" channel."<<endl;
  return out;
}
ostream& operator <<(ostream & out, const movie & mov)
{
  out<<"Movie "<< mov.m_Name<<" is playing at "
  <<mov.m_Theater<<" theater."<<endl;
  return out;
}
void fill_tv(tv_show tv_array[])
{
  string name;
  for(int i=0;i<SIZE;i++)
  {
    cout<<"Enter a tv show from that network: "<<endl;
    cin>>name;
    tv_array[i].setname(name);
    name="";
  }
  return;
}

void fill_movie(movie movie_array[])
{
  string name;
  for(int i=0;i<SIZE;i++)
  {
    cout<<"Enter a movie from that theater: "<<endl;
    cin>>name;
    movie_array[i].setname(name);
    name="";
  }
  return;
}