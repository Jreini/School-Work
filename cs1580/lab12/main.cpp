//Programmer: Justin Reini  Date: 04/14/2020
//File: main.cpp  Class: Lab 301
//Description: Main file for the tv program

#include "tv.h"

string tv_show::m_Station = "NBC";
string movie::m_Theater="Marcus";
int main()
{
  string network;
  string theater;
  tv_show tv_array[SIZE];
  movie movie_array[SIZE];
  cout<<"\tWelcome to The TV/Movie Program"<<endl;
  cout<<"Enter a network: "<<endl;
  cin>>network;
  tv_array[0].setStation(network);
  fill_tv(tv_array);
  cout<<"Enter a movie theater: "<<endl;
  cin>>theater;
  movie_array[0].setTheater(theater);
  fill_movie(movie_array);
  for(int i=0; i<SIZE;i++) //Print network
  {
    cout<<tv_array[i];
  }
  for(int i=0; i<SIZE;i++) //Print movies
  {
    cout<<movie_array[i];
  }
  cout<<endl;
  cout<<"Enter a new network: "<<endl;
  cin>>network;
  tv_array[0].setStation(network);  //Change network
  cout<<"enter a new theater: "<<endl;
  cin>>theater;
  movie_array[0].setTheater(theater);  //Change theater
  for(int i=0; i<SIZE;i++)
  {
    cout<<tv_array[i];
  }
  for(int i=0; i<SIZE;i++)
  {
    cout<<movie_array[i];
  }
  return 0;
}
