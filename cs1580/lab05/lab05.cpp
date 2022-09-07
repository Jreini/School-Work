//Programmer: Justin Reini  Date: 02/18/2020
//File: lab05.cpp  Class: Lab 301
//Description: Island Base Builder

#include <iostream>
using namespace std;

int main()
{
  //Variable Declaration
  int Player_Option;
  int Build_Option;
  int island_select;
  int build_result;
  bool Suitable_Living=false;
  bool Buildings_Complete=false;
  bool done=false;
  bool house=false;
  bool training=false;
  bool stables=false;
  bool travel=false;
  bool defense=false;


  //rand nums
  srand(time(NULL));

  //Welcome message
  cout<<"Hello and welcome to the island builder"<<endl;
  do
  {
    cout<<"Please choose an option below"<<endl<<endl;
    cout<<"1. Search for an island"<<endl;
    cout<<"2. Build on the island"<<endl;
    cout<<"3. Complete the island"<<endl<<endl;

    cin>>Player_Option;

    //Branching
    switch (Player_Option)
    {
    case 1:  //Selecting an island
      do
      {
        island_select=1+rand()%(4-1+1);
        switch (island_select)
        {
            case 1:
              cout<<"Dangerous and unusuable"<<endl;
              break;
            case 2:
              cout<<"Inhabited by dangerous dragons,not usable"<<endl;
              break;
            case 3:
              cout<<"Base for trappers, unusable"<<endl;
              break;
            case 4:
              cout<<"Suitable conditions. Base can be built here"<<endl;
              Suitable_Living=true;
              break;
        } 
      } while(!Suitable_Living); 
      break;
    case 2:  //Building an island
      if (Suitable_Living==false)
      {
        cout<<"You do not have an island with sutiable living standards"<<endl;
        cout<<"Please go choose option 1"<<endl;
        break;
      }
      do
      {
        cout<<"Please choose a build option below"<<endl<<endl;
        cout<<"1. Build Housing"<<endl;
        cout<<"2. Build training area"<<endl;
        cout<<"3. Build stables"<<endl;
        cout<<"4. Build travel systems"<<endl;
        cout<<"5. Build defenses"<<endl<<endl;

        cin>>Build_Option;
        switch (Build_Option)  //Building bases
        {
              case 1:
              build_result=1+rand()%(2-1+1);
              if (build_result==1)
              {
                cout<<"Housing is complete. On to the next!"<<endl;
                house=true;
              }
              else 
                cout<<"Ran into some issues, try again"<<endl;
              break;
            case 2:
              build_result=1+rand()%(2-1+1);
              if (build_result==1)
              {
                cout<<"Training area is complete. On to the next!"<<endl;
                training=true;
              }
              else 
                cout<<"Ran into some issues, try again"<<endl;
              break;
            case 3:
              build_result=1+rand()%(2-1+1);
              if (build_result==1)
              {
                cout<<"Stables are complete. On to the next!"<<endl;
                stables=true;
              }
              else 
                cout<<"Ran into some issues, try again"<<endl;
              break;
            case 4:
              build_result=1+rand()%(2-1+1);
              if (build_result==1)
              {
                cout<<"Travel Systems are complete. On to the next!"<<endl;
                travel=true;
              }
              else 
                cout<<"Ran into some issues, try again"<<endl;
              Suitable_Living=true;
              break;
            case 5:
              build_result=1+rand()%(2-1+1);
              if (build_result==1)
              {
                cout<<"Defense Systems are complete. On to the next!"<<endl;
                defense=true;
              }
              else 
                cout<<"Ran into some issues, try again"<<endl;
            default:
              cout<<"Enter a number 1-5"<<endl;
              break;
        } 
        if (house==true && training==true && stables==true && travel==true
        && defense==true)
          Buildings_Complete=true;
      } while(!Buildings_Complete); 
      
      break;
    case 3:  //Completing the island
      if (Suitable_Living==true && Buildings_Complete==true)
      {      
        cout<<"Island is complete, time to explore!"<<endl;
        done=true;
      }
      else
        cout<<"You are not done building yet, come back when you finish"<<endl;
      break;
    default:
      cout<<"Enter a number 1-3"<<endl;
      break;
    } 







  } while (!done);

  return 0;
}
