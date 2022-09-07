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
//Kruskal's Algorithm
#define size 10

class Edge {
public:
    int src, dest, weight;
};
 
// class to describe a graph with array of edges
class Graph {
public:
     
    int V, E;  //V=vertices E=edges
 

    Edge* edge;
};
 
// Creates a graph with V vertices and E edges
Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
 
    graph->edge = new Edge[E];
 
    return graph;
}
 
//subset to handle findings
class subset {
public:
    int parent;
    int rank;
};
 
// find set of an element i
int find(subset subsets[], int i)
{
    // find root and make root as parent 
    if (subsets[i].parent != i)
        subsets[i].parent
            = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets
void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    // Attach smaller rank tree 
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and increment the rank
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
// Compare two edges according to their weights.
int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}
 
// The main function to construct MST 
void KruskalMST(Graph* graph)
{
    int V = graph->V;
    Edge result[V]; //resultant MST
    int e = 0; // Index variable
    int i = 0; // Index variable
 
    // Step 1: Sort all the edges in non-decreasing order of weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),
          myComp);
 //Invariant: graph contains edges for minimal spanning tree <V-1
    // Allocate memory 
    subset* subsets = new subset[(V * sizeof(subset))];
 
    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E)
    {
        //Pick the smallest edge, increment
        Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
 
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
//Invariant: graph contains edges for minimal spanning tree <V      
    }
 
    // print MST
    cout << "Following are the edges in the constructed "
            "MST\n";
    int minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        cout << result[i].src << " -- " << result[i].dest
             << " == " << result[i].weight << endl;
        minimumCost = minimumCost + result[i].weight;
    }
    cout << "Minimum Cost Spanning Tree: " << minimumCost
         << endl;
//Invariant: graph contains all edges for minimal spanning tree 
}

//Dijsktra algorithm
int minDistance(int dist[], bool sptSet[])
{
   
    // min
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < size; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
// print constructed array
void printSolution(int dist[])
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < size; i++)
        cout  << i << " \t\t"<<dist[i]<< endl;
}
 
// graph function
void dijkstra(int graph[size][size], int src)
{
    int dist[size]; // Distance array
 
    bool sptSet[size]; //seperate set

    // Initialize all distances as infinite
    for (int i = 0; i < size; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
//Invariant: dist is a subtree of MST not equal to V-1
    // Distance of source vertex  is always 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < size - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices
        int u = minDistance(dist, sptSet);
//Invariant: dist is a subtree with i vertices in sptSet
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < size; v++)
//Invariant: sptSet is a subtree with v+1 vertices of MST tree
            // Update dist[v] only if is not in sptSet
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
//Invariant: sptSet is a MST with vertices-1
    // print the array
    printSolution(dist);
}
 

int main()
{
    
    int table[size][size] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0, 0},
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0, 0 },
                        { 0, 8, 0, 7, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 7, 0, 0, 14, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 10, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
                
    auto start2 = high_resolution_clock::now();
    dijkstra(table, 0);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout<<"Time taken by the Dujkstra's algorithm: "<<duration2.count()<<" microseconds"<<endl<<endl;
    int V = 10; // Number of vertices in graph
    int E = 11; // Number of edges in graph
    Graph* graph = createGraph(V, E);
 
    //0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 4;
 
    //0-7
    graph->edge[1].src = 0;
    graph->edge[1].dest = 7;
    graph->edge[1].weight = 8;
 
    //1-0
    graph->edge[2].src = 1;
    graph->edge[2].dest = 0;
    graph->edge[2].weight = 4;
 
    //1-2
    graph->edge[3].src = 1;
    graph->edge[3].dest = 2;
    graph->edge[3].weight = 8;
 
    //1-7
    graph->edge[4].src = 1;
    graph->edge[4].dest = 7;
    graph->edge[4].weight = 11;

    //2-1
    graph->edge[5].src = 2;
    graph->edge[54].dest = 1;
    graph->edge[5].weight = 8;

    //2-3
    graph->edge[6].src = 2;
    graph->edge[6].dest = 3;
    graph->edge[6].weight = 7;

    //3-2
    graph->edge[7].src = 3;
    graph->edge[7].dest = 2;
    graph->edge[7].weight = 7;

    //3-5
    graph->edge[8].src = 3;
    graph->edge[8].dest = 5;
    graph->edge[8].weight = 14;

    //5-4
    graph->edge[9].src = 5;
    graph->edge[9].dest = 4;
    graph->edge[9].weight = 10;

    //7-6
    graph->edge[10].src = 7;
    graph->edge[10].dest = 6;
    graph->edge[10].weight = 1;


    //Timing 
    auto start = high_resolution_clock::now();
    KruskalMST(graph);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout<<"Time taken by the Kruskal: "<<duration.count()<<" microseconds"<<endl<<endl;

 
    return 0;
}
 