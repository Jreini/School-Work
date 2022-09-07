//Programmer: Justin Reini  Date: 03/03/2020
//File: lab07.cpp  Class: Lab 301
//Description: To feed the riders and the dragons after a tough battle

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
//Description: The pile_refil() function will refil the pile and return nothing
//Pre condition: Must have a positive communal food
//Post condition: Communal food updated
void pile_refil(int & Communal_Food,int & carry);
/*Description: The rider_feed() function will feed the rider and
  update the rider food eaten ammount */
//Pre condition: Must have a positive rider_food_eaten
//Post condition: Rider Food eaten updated
void rider_feed(int & rider_food, int & Communal_Food);
/*Description: The dragon_feed() function will feed the dragon and 
  update the dragon food eaten ammount */
//Pre condition: Must have a positive dragon_food_eaten
//Post condition: Dragon food eaten updated
void dragon_feed(int & dragon_food, int & Communal_Food);
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
const int RIDER_EAT_MAX=30;
const int RIDER_CARRY_MIN=10;
const int RIDER_CARRY_MAX=15;
const int RIDER_EAT_PER_TURN=10;

const int DRAGON_EAT_PER_TURN=25;
int main()
{
  //Variable Declarations
  srand(time(NULL)); //Rand num generation
  const int RIDER_ARRAY_SIZE=6;
  const int DRAGON_ARRAY_SIZE=5;
  const int DRAGON_EAT_MAX=100+rand()%(150-100+1);
  riders riders_array[RIDER_ARRAY_SIZE];
  dragons dragon_array[DRAGON_ARRAY_SIZE];
  bool all_full=false;
  int Communal_Food;
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
      if (riders_array[i].m_rider_food_eaten>=RIDER_EAT_MAX) //Checks if full
        riders_array[i].m_rider_full=true;
      else if (Communal_Food>=RIDER_EAT_PER_TURN) //Checks communal food
      {
        
        rider_feed(riders_array[i].m_rider_food_eaten,Communal_Food);
      }
      else if (Communal_Food<RIDER_EAT_PER_TURN) //refils pile
      {
        pile_refil(Communal_Food,riders_array[i].m_rider_carry);
      }
    }
    for (int i=0; i<5; i++) //Dragons eating
    {
      if (dragon_array[i].m_dragon_food_eaten>=DRAGON_EAT_MAX) //checks if full
        dragon_array[i].m_dragon_full=true;
      else if (Communal_Food>=DRAGON_EAT_PER_TURN) //Checks communal food
      {
        dragon_feed(dragon_array[i].m_dragon_food_eaten,Communal_Food);
      }
      else if (Communal_Food<DRAGON_EAT_PER_TURN) //refil pile
      {
        pile_refil(Communal_Food,riders_array[i].m_rider_carry);
      }
    }
    if (dragon_array[0].m_dragon_full==true&&
      dragon_array[1].m_dragon_full==true&&
      dragon_array[2].m_dragon_full==true&&
      dragon_array[3].m_dragon_full==true&&
      dragon_array[4].m_dragon_full==true&&
      riders_array[0].m_rider_full==true&&
      riders_array[1].m_rider_full==true&&
      riders_array[2].m_rider_full==true&&
      riders_array[3].m_rider_full==true&&
      riders_array[4].m_rider_full==true&&
      riders_array[5].m_rider_full==true) //checks to see if they are all full
      all_full=true;
    else
      cout<<"End round of feeding"<<endl<<endl;
  }while (all_full==false);
  cout<<"All dragons and riders are full!"<<endl;
  return 0;
}
void pile_refil(int & Communal_Food, int & carry) //pile refil
{
  cout<<"Refiling pile"<<endl;
  srand(time(NULL)); //Rand num generation
  carry= RIDER_CARRY_MIN+rand()%(RIDER_CARRY_MAX-RIDER_CARRY_MIN+1);
  Communal_Food=Communal_Food+carry;
  carry=0;
  return;
}
void rider_feed(int & rider_food,int & Communal_Food) //rider feed
{
  int new_rider_total;
  cout<<"Feeding rider"<<endl;
  new_rider_total=RIDER_EAT_PER_TURN+rider_food;
  rider_food=new_rider_total;
  Communal_Food=Communal_Food-rider_food;
  return;
}
void dragon_feed(int & dragon_food, int & Communal_Food) //dragon feed
{
  int new_dragon_total;
  cout<<"Feeding dragon"<<endl;
  new_dragon_total=DRAGON_EAT_PER_TURN+dragon_food;
  dragon_food=new_dragon_total;
  Communal_Food=Communal_Food-dragon_food;
  return;
}

