//Programmer: Justin Reini  Date: 02/11/2020
//File: lab04.cpp  Class: Lab 301
//Description: Dragon Feeder

#include <iostream>
using namespace std;

int main()
{
  //Variable Declaration
  const int CARRY_LIMIT=10;
  const int FEED_AMOUNT=10;
  const int FEED_GOAL=100;

  int Hiccup=70;
  int Toothless=0;

  int Astrid=60;
  int Stormfly=0;

  int Fishlegs=50;
  int Meatlug=0;

  int Snotlout=40;
  int Hookfang=0;

  int Rufnut_Tufnut=20;
  int Barf_Belch=0;
  
  //Feeding dragons block
  while(Toothless<FEED_GOAL)
  {
    if(Hiccup>=FEED_AMOUNT)
    {  
      Toothless=Toothless+FEED_AMOUNT;
      Hiccup=Hiccup-FEED_AMOUNT;
    }
    else
      Hiccup=Hiccup+CARRY_LIMIT;
  }
  if(FEED_GOAL==Toothless)  //Check to see if Toothless is full
    cout<<"Toothless is all full"<<endl;
  
  while(Stormfly<FEED_GOAL)
  {
    if(Astrid>=FEED_AMOUNT)
    {
      Stormfly=Stormfly+FEED_AMOUNT;
      Astrid=Astrid-FEED_AMOUNT;
    }
    else
      Astrid=Astrid+CARRY_LIMIT;
  }
  if(FEED_GOAL==Stormfly)  //Check to see if Stormfly is full
    cout<<"Stormfly is all full"<<endl;

  while(Meatlug<FEED_GOAL)
  {
    if(Fishlegs>=FEED_AMOUNT)
    {
      Meatlug=Meatlug+FEED_AMOUNT;
      Fishlegs=Fishlegs-FEED_AMOUNT;
    }
    else
      Fishlegs=Fishlegs+CARRY_LIMIT;
  }
  if(FEED_GOAL==Meatlug)  //Check to see if Meatlug is full
    cout<<"Meatlug is all full"<<endl;

  while(Hookfang<FEED_GOAL)
  {
    if(Snotlout>=FEED_AMOUNT)
    {
      Hookfang=Hookfang+FEED_AMOUNT;
      Snotlout=Snotlout-FEED_AMOUNT;
    }
    else
      Snotlout=Snotlout+CARRY_LIMIT;
  }
  if(FEED_GOAL==Hookfang)  //Check to see if Hookfang is full
    cout<<"Hookfang is all full"<<endl;

  while(Barf_Belch<FEED_GOAL)
  {
    if(Rufnut_Tufnut>=FEED_AMOUNT)
    {
      Barf_Belch=Barf_Belch+FEED_AMOUNT;
      Rufnut_Tufnut=Rufnut_Tufnut-FEED_AMOUNT;
    }
    else
      Rufnut_Tufnut=Rufnut_Tufnut+CARRY_LIMIT;
  }
  if(FEED_GOAL==Barf_Belch)  //Check to see if Barf and Belch are full
    cout<<"Barf and Belch are both full"<<endl;

  if(FEED_GOAL==Toothless&&FEED_GOAL==Stormfly&&FEED_GOAL==Meatlug&&
  FEED_GOAL==Hookfang&&FEED_GOAL==Barf_Belch)  //Make sure all are full
    cout<<"Feeding time is over"<<endl;

  return 0;

}



