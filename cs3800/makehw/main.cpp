#include <vector>
#include <iostream>

using namespace std;
int main()
{   
    vector<int> foo = {1, 2, 3};
    for(int i = 0; i<(foo.size()+4); i++)
    {
        cout << foo[i] << endl;
    }
}