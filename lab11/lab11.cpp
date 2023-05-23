#include <bits/stdc++.h>
using namespace std;
 

#define V 6 // 6 vertices in the graph
 
//finding the vertex with the minimum key value
int minV(int Ver[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && Ver[v] < min)
            min = Ver[v], min_index = v;
 
    return min_index;
}
 

//printing the MST
void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}
 

void primMST(int graph[V][V])
{

    int parent[V];
    int Ver[V];
    bool mstSet[V];
 
    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        Ver[i] = INT_MAX, mstSet[i] = false;
 
    Ver[0] = 0;
   
 
    parent[0] = -1;
 
    
    for (int count = 0; count < V - 1; count++) {
        
        int u = minV(Ver, mstSet);

        mstSet[u] = true;
 
        for (int v = 0; v < V; v++)
 
           
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < Ver[v])
                parent[v] = u, Ver[v] = graph[u][v];
    }
 
    
    printMST(parent, graph);
}
 

int main()
{
    //code to deliver the output
    int G[V][V] = { { 0, 3, 0, 0, 0, 1},
                        { 3, 0, 2, 1, 10, 0},
                        { 0, 2, 0, 3, 0, 5},
                        { 0, 1, 3, 0, 5, 0},
                        { 0, 10, 0, 5, 0, 5},
                        { 1, 0, 5, 0, 5, 0} };
 
    
    primMST(G);//printing the solution
 
    return 0;
}