// Programmer: Justin Reini

#include <iostream>
#include <cstring>
#include <cstdlib>  
#include <ctime>
#include <algorithm>
#include <chrono>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;   

//Dynamic approach 

int max(int a, int b) //Max function that will be used for comparison later
{
    return (a > b) ? a : b;
}
 

int knapSackTable(int W, int wt[], int val[], int n)
{
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));
 
    for(i = 0; i <= n; i++)  //Build table starting from bottom
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];  //Return best solution
}

//Greedy Approach
int GreedyknapSack(int W, int wt[], int val[], int n)
{

    if (n == 0 || W == 0)  //Base case
        return 0;
 

    if (wt[n - 1] > W) //Weight is greater than Sack Weight so must be discarded
        return GreedyknapSack(W, wt, val, n - 1);
 
    else  //Find out if the total Weight is bigger with the nth item included or not
        return max(
            val[n - 1]
                + GreedyknapSack(W - wt[n - 1],
                           wt, val, n - 1),
            GreedyknapSack(W, wt, val, n - 1));
}
 


int main()
{
    int val[] = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50 }; //Values of test items
    int wt[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };  //Weights of test items
    int W = 15000;  //Weight of bag
    int n = sizeof(val) / sizeof(val[0]);
    int greed, table;

    //Time functions

    auto start = high_resolution_clock::now();
    greed = GreedyknapSack(W, wt, val, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout<<"For weight "<<W<<", the greedy solution is: "<<greed<<endl;
    cout<<"Time taken by the greedy approach: "<<duration.count()<<" microseconds"<<endl<<endl;

    auto start2 = high_resolution_clock::now();
    table = knapSackTable(W, wt, val, n);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    cout<<"For weight "<<W<<", the table solution is: "<<table<<endl;
    cout<<"Time taken by the table approach: "<<duration2.count()<<" microseconds"<<endl;

    
     
    return 0;
}