//Programmer: Justin Reini  Date: 03/03/2020
//File: lab07.cpp  Class: Lab 301
//Description: To feed the riders and the dragons after a tough battle

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
srand(time(NULL));  //Rand num generation
/*Description: The pile_refil() function will refil the pile and return
  a random amount of food to the pile */
//Pre condition: Must have a positive communal food
//Post condition: The new communal food pile was returned
int pile_refil(int food_storage,int carry);
/*Description: The rider_feed() function will feed the rider and return
  the rider's new current food eaten ammount */
//Pre condition: Must have a positive rider_food_eaten
//Post condition: The rider was fed and given a new value
void rider_feed(int rider_food);
/*Description: The dragon_feed() function will feed the dragon and return
  the dragon's new current food eaten ammount */
//Pre condition: Must have a positive dragon_food_eaten
//Post condition: The dragon was fed and given a new value
int dragon_feed(int dragon_food);
//Struct of riders containing name,carry,food eaten and if they are full
struct riders
{
  string m_rider_name;
  int m_rider_food_eaten=0;
  int m_rider_carry;
  bool m_rider_full=false;
};
//Struct of dragons contaning name,carry,food eaten and if they are full
struct dragons
{
  string m_dragon_name;
  int m_dragon_food_eaten=0;
  int m_dragon_feeding;
  bool m_dragon_full=false;
};
srand(time(NULL)); //Rand num generation
const int RIDER_EAT_MAX=30;
const int RIDER_CARRY_MIN=10;
const int RIDER_CARRY_MAX=15;
const int RIDER_EAT_PER_TURN=10;

const int DRAGON_EAT_PER_TURN=25;
const int DRAGON_EAT_MAX=100+rand()%(150-100+1);
int main()
{
  //Variable Declarations
  const int RIDER_ARRAY_SIZE=6;
  const int DRAGON_ARRAY_SIZE=5;
  riders riders_array[RIDER_ARRAY_SIZE];
  dragons dragon_array[DRAGON_ARRAY_SIZE];
  bool all_full=false;
  int add_food;
  Communal_Food=50+rand()%(100-50+1); //Food generation
  //Welcome message
  cout<<"Welcome to the feast!"<<endl<<endl;

  for (int i=0; i<6; i++) //Entering rider names
  {
    cout<<"Enter a rider name:"<<endl;
    cin>>riders_array[i].m_rider_name;
  }
  for (int i=0; i<5; i++) //Emtering dragon names
  {
    cout<<"Enter a dragon name:"<<endl;
    cin>>dragon_array[i].m_dragon_name;
  }
  do
  {
    for (int i=0; i<6; i++) //Riders eating
    {
      if (riders_array[i].m_rider_food_eaten==RIDER_EAT_MAX) //Checks if full
        riders_array[i].m_rider_full=true;
      else if (Communal_Food>=RIDER_EAT_PER_TURN) //Checks communal food
      {
        riders_array[i].m_rider_food_eaten=riders_array[i].m_rider_food_eaten+
        rider_feed();
      }
      else if (Communal_Food<RIDER_EAT_PER_TURN) //refils pile
      {
          Communal_Food=Communal_Food+pile_refil();
      }
    }
    for (int i=0; i<5; i++) //Dragons eating
    {
      if (dragon_array[i].m_dragon_food_eaten==DRAGON_EAT_MAX) //checks if full
        dragon_array[i].m_dragon_full=true;
      else if (Communal_Food>=DRAGON_EAT_PER_TURN) //Checks communal food
      {
        dragon_feed(dragon_array[i].m_dragon_food_eaten);
      }
      else if (Communal_Food<DRAGON_EAT_PER_TURN) //refil pile
      {
        pile_refil(Communal_Food);
      }
    }
    if (dragon_array[0].m_dragon_full=true&&dragon_array[1].m_dragon_full=true&&
      dragon_array[2].m_dragon_full=true&&dragon_array[3].m_dragon_full=true&&
      dragon_array[4].m_dragon_full=true&&riders_array[0].m_rider_full=true&&
      riders_array[1].m_rider_full=true&&riders_array[2].m_rider_full=true&&
      riders_array[3].m_rider_full=true&&riders_array[4].m_rider_full=true&&
      riders_array[5].m_rider_full=true)
      all_full=true;
  }while (all_full=false);
  cout<<"All dragons and riders are full!"<<endl;
  return 0;
}
int pile_refil(int food_storage=0, int carry) 
{
  cout<<"Refiling pile"<<endl;
  carry= RIDER_CARRY_MIN+rand()%(RIDER_CARRY_MAX-RIDER_CARRY_MIN+1);
  food_storage=food_storage+carry;
  return food_storage;
}
void rider_feed(int rider_feed)
{
  dra
}
int dragon_feed()
{
  
}