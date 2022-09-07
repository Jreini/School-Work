//Programmer: Justin Reini  Date: 02/25/2020
//File: lab06.cpp  Class: Lab 301
//Description: The first battle

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
struct hunter_ships
{
  int m_ships_health;
  int m_ship_crew;
  bool m_captured_dragon=false;
};

struct dragon_riders
{
  string m_rider_name;
  string m_dragon_name;
  int m_dragon_health;
  bool m_captured_dragon=false;
};

int main()
{
  //Variable Declarations
  const int HUNTER_ARRAY_SIZE=7;
  const int DRAGON_ARRAY_SIZE=5;
  hunter_ships ships_array[HUNTER_ARRAY_SIZE];
  dragon_riders dragon_array[DRAGON_ARRAY_SIZE];
  bool ships_sunk=false;
  bool dragons_captured=false;
  int dragon_attack;
  int ship_attack;

  srand(time(NULL));  //Rand num generation

  cout<<"Welcome to the first battle"<<endl;
  for (int i=0; i<5; i++)
  {
    cout<<"Enter a rider name"<<endl;
    cin>>dragon_array[i].m_rider_name;
  }
  for (int i=0; i<5; i++)
  {
    cout<<"Enter a dragon name"<<endl;
    cin>>dragon_array[i].m_dragon_name;
  }
  
  for (int i=0; i<5; i++)
    dragon_array[i].m_dragon_health= 15+rand()%(20-15+1);
  for (int i=0; i<7; i++)
  {
    ships_array[i].m_ships_health= 30+rand()%(40-30+1);
    ships_array[i].m_ship_crew= 10+rand()%(15-10+1);
  }
  do
  {
    cout<<"Round Start"<<endl;
    for (i=0; i<5; i++)  //dragons attack
    {
      dragon_attack=1+rand()%(10-1+1);
      if (dragon_attack<=7)
      {
        if ships_array[i].m_ships_health>0
        {
          cout<<"Hit!"<<endl;
          ships_array[i].m_ships_health=ships_array[i].m_ships_health-
          (5+rand()%(10-5+1));
          if ships_array[i].m_ships_health==0
            cout<<"Ship #"<<i<<" is sunk!"<<endl;
        }
      }
      else if (dragon_attack>7)
        cout<<"Miss"<<endl;
    }
    for (i=0;i<5; i++)  //ships attack
    {
      ship_attack=1+rand()%(10-1+1);
      if (ship_attack<=4)
      {
  } while (ships_sunk=false && dragons_captured=false);
  return 0;
}