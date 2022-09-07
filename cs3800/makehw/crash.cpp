#include <iostream>
#include <stdlib.h>

using namespace std;

void loopy();

int main()
{ 
  loopy();
  loopy();
  return 0;
}

void loopy()
{
  for(int i = 0; i <= 10; i--)
  {
    cout << i << endl;
  }
  return;
}