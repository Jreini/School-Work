//Programmer: Justin Reini  Date: 04/14/2020
//File: tv.h  Class: Lab 301
/*Description: This file contains prototypes for functions used in the 
tv program*/

#ifndef TV_H
#define TV_H

#include <iostream>
#include <cstring>
using namespace std;

//Global Constants
const int SIZE=5;

//tv_show Class
/*This class is used to store tv shows and their network*/

/*Description: The getname() function returns the member variable
for the show name*/
//Pre: None
//Post: The member variable for the name of the show is returned

/*Description: The setname() function sets the name of the show to the
class member variable for the name of the show*/
//Pre: The show name must be passed in
//Post: The show name is set to the member variable for the show name

/*Description: The getStation() function returns the member variable
for the station name*/
//Pre: None
//Post: The member variable for the name of the station is returned

/*Description: The setStation() function sets the name of the station to the
class member variable for the name of the station*/
//Pre: The station name must be passed in
//Post: The station name is set to the member variable for the station name

/*Description: The operator<<() function takes in the tv show and its channel
and defines the << operator in order to print out the show name and 
its station to the user*/
//Pre: The tv show object must be passed in
/*Post: The tv show along with its station is returned and printed to the
user*/
class tv_show
{
  public:
    string getname();
    void setname(const string name);
    string getStation();
    void setStation(const string station);
    friend ostream& operator <<(ostream & out, const tv_show & tv);
  private:
    string m_Name;
    static string m_Station;
};

//movie Class
/*This class is used to store movies and their theater*/

/*Description: The getname() function returns the member variable
for the movie name*/
//Pre: None
//Post: The member variable for the name of the movie is returned

/*Description: The setname() function sets the name of the movie to the
class member variable for the name of the movie*/
//Pre: The movie name must be passed in
//Post: The movie name is set to the member variable for the movie name

/*Description: The getTheater() function returns the member variable
for the Theater name*/
//Pre: None
//Post: The member variable for the name of the Theater is returned

/*Description: The setTheater() function sets the name of the Theater to the
class member variable for the name of the Theater*/
//Pre: The Theater name must be passed in
//Post: The Theater name is set to the member variable for the Theater name

/*Description:The operator<<() function takes in the movie name and its theater
and defines the << operator in order to print out the movie name and 
its theater to the user*/
//Pre: The movie object must be passed in
/*Post: The movie along with its theater is returned and printed to the
user*/

class movie
{
  public:
    string getname();
    void setname(const string name);
    string getTheater();
    void setTheater(const string theater);
    friend ostream& operator <<(ostream & out, const movie & mov);
  private:
    string m_Name;
    static string m_Theater;
};

//Function Declarations
/*Description: The fill_tv() function will take in empty array and fill it
with tv shows from the tv_shows class*/
//Pre: An empty array must be passed in
//Post: The tv array is filled
void fill_tv(tv_show tv_array[]);

/*Description: The fill_movie() function will take in empty array and fill it
with movies from the movie class*/
//Pre: An empty array must be passed in
//Post: The movie array is filled
void fill_movie(movie movie_array[]);

#endif