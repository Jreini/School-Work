// Programmer: Justin Reini

#include <iostream>
#include <cstring>
#include <cstdlib>  
#include <ctime>
#include <algorithm>
#include <chrono>
#include<vector>
#include <bits/stdc++.h>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;
using namespace std::chrono;   

//Edmonds-Karp Algorithm

#define vertices 10

//First function, pathcheck, returns true if there is a path from source to sink
bool pathcheck(int residGraph[vertices][vertices], int s, int t, int parent[])
{
    // Create a visited array and mark those not visited
    bool visited[vertices];
    memset(visited, 0, sizeof(visited));
 
    // Create a queue and add source vertex 
    queue<int> q;
    q.push(s);

    //mark the source vertex as visited
    visited[s] = true;
    parent[s] = -1;
 
    // Function loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 0; v < vertices; v++) {
            if (visited[v] == false && residGraph[u][v] > 0) {
                // If connection made to sink then set parent and return true
                if (v == t) 
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    // Didn't reach sink so return false
    return false;
}
 
// Returns the maximum flow from s to t in the given graph
int EdmondKarp(int graph[vertices][vertices], int s, int t)
{
    int u, v;
 
    
    int residGraph[vertices][vertices]; //Residual graph holding capacity of edges 
    //For example, residGraph[x][y] indicates residual capacity of an edge from x to y 
        
    for (u = 0; u < vertices; u++)
        for (v = 0; v < vertices; v++)
            residGraph[u][v] = graph[u][v];  //copies graph
 
    int parent[vertices]; // This array stores paths from pathcheck()
                  
 
    int max_flow = 0; // No flow initially
 
    //loop to be repeated while there are augmented paths from source to sink
    while (pathcheck(residGraph, s, t, parent)) {
        // find max flow through path found
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, residGraph[u][v]);
        }
 
        //update residual capacities
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            residGraph[u][v] -= path_flow;
            residGraph[v][u] += path_flow;
        }
 
        // Add path flow to overall flow
        max_flow += path_flow;
    }
 
    // Return the final max flow
    return max_flow;
}
 

int main()
{
    int x;
    // Graph creation
    int graph[vertices][vertices]
        = { { 0, 12, 18, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 4, 9, 7, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 6, 10, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 7, 0, 0, 0, 0 },
            { 0, 0, 0, 3, 0, 0, 9, 0, 0, 0 },  { 0, 0, 0, 0, 8, 0, 0, 14, 0, 0 },
            { 0, 0, 0, 2, 0, 6, 0, 0, 14, 0 },   { 0, 0, 0, 0, 0, 0, 11, 0, 13, 11 }, 
            { 0, 0, 0, 0, 0, 9, 0, 0, 0, 22 },   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
    auto start = high_resolution_clock::now();
    x= EdmondKarp(graph, 0, 5);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    //Outputs
    cout<<"Maximum possible flow is "<<x<<endl;
    cout<<"Time taken by the Edmonds-Karp algorithm: "<<duration.count()<<" microseconds"<<endl<<endl;
 
    return 0;
}