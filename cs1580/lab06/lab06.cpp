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
  int crew_attack;

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
    for (int i=0; i<5; i++)  //dragons attack-ship damage
    { 
      dragon_attack=1+rand()%(10-1+1);
      if (dragon_attack<=7)
      { 
        for (int i=0; i<7; i++)
        { 
          if (ships_array[i].m_ships_health>0)
          {
            cout<<"Hit ship!"<<endl;
            ships_array[i].m_ships_health=ships_array[i].m_ships_health-
            (5+rand()%(10-5+1));
            if (ships_array[i].m_ships_health<=0)
              cout<<"Ship Sunk!"<<endl;
            break;
          }
        }
      }
      else if (dragon_attack>7)
        cout<<"Miss ship"<<endl;
    }
    for (int i=0;i<5; i++) //dragons attack -crew damage
    { 
      crew_attack=1+rand()%(10-1+1);
      if (crew_attack<=3)
      { 
        for (int i=0; i<7; i++)
        { 
          if (ships_array[i].m_ship_crew>0)
          {
            cout<<"Hit crew!"<<endl;
            ships_array[i].m_ship_crew=ships_array[i].m_ship_crew-
            (2+rand()%(3-2+1));
            if (ships_array[i].m_ship_crew<=0)
              cout<<"Crew killed!"<<endl;
            break;
          }
        }
      }
      else if (crew_attack>3)
        cout<<"Miss crew!"<<endl;
    }
    for (int i=0;i<7; i++)  //ships attack
    { 
      ship_attack=1+rand()%(10-1+1);
      if (ship_attack<=4)
      { 
        for (int i=0; i<5; i++)
        { 
          if (dragon_array[i].m_dragon_health>0)
          {
            cout<<"Hit dragon!"<<endl;
            dragon_array[i].m_dragon_health=dragon_array[i].m_dragon_health-
            (5+rand()%(5-4+1));
            if (dragon_array[i].m_dragon_health<=0)
              cout<<"Dragon Captured!"<<endl;
            break;
          }
        }
      }
      else if (dragon_attack>4)
        cout<<"Miss dragon"<<endl;
    }
    if (((ships_array[0].m_ships_health<=0)||(ships_array[0].m_ship_crew<=0))&& 
    ((ships_array[1].m_ships_health<=0) || (ships_array[1].m_ship_crew<=0))&&
    ((ships_array[2].m_ships_health<=0) || (ships_array[2].m_ship_crew<=0))&&
    ((ships_array[3].m_ships_health<=0) || (ships_array[3].m_ship_crew<=0))&&
    ((ships_array[4].m_ships_health<=0) || (ships_array[4].m_ship_crew<=0))&&
    ((ships_array[5].m_ships_health<=0) || (ships_array[5].m_ship_crew<=0))&&
    ((ships_array[6].m_ships_health<=0) || (ships_array[6].m_ship_crew<=0)))
      ships_sunk=true;
    if ((dragon_array[0].m_dragon_health<=0) && 
    (dragon_array[1].m_dragon_health<=0) &&
    (dragon_array[2].m_dragon_health<=0) &&
    (dragon_array[3].m_dragon_health<=0) &&
    (dragon_array[4].m_dragon_health<=0))
      dragons_captured=true;
  } while (ships_sunk==false && dragons_captured==false);
  if (ships_sunk==true)
  {
    cout<<"Dragons win!"<<endl;
    for (int i=0;i<5;i++)
    {
      if (dragon_array[i].m_dragon_health>0)
      {
        cout<<dragon_array[i].m_dragon_name<< " has "<<
        dragon_array[i].m_dragon_health<<" health left."<<endl;
      }
    }
  }
  if (dragons_captured==true)
  {
    cout<<"Hunters win!"<<endl;
    for (int i=0;i<7;i++)
    {
      if ((ships_array[i].m_ship_crew>0)&&(ships_array[i].m_ships_health>0))
      {
        cout<<"Ship "<<i<<" has "<<ships_array[i].m_ships_health<<" health left and "<<
        ships_array[i].m_ship_crew<<" crew members left."<<endl;
      }
    }
  }
  return 0;
}

