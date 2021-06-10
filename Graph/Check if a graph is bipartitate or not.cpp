#include <iostream>
#include <bits\stdc++.h>
using namespace std;
#define V 4


// Check if a graph is bipartitate or not

bool isBipartite(int graph[][V],int u){
    int colour[V];
    bool visited[V];

    for(int i =0; i<V ; i++){
        colour[i] = INT_MAX;
    }

    queue<int> qu; colour[u] = 1;
    qu.push(u); int child;

    while(!qu.empty()){
        u = qu.front();
        qu.pop();

        for(int v = 0; v<V ; v++){
            child = graph[u][v];
            if(child != 0){
                if(colour[v] == INT_MAX){
                    colour[v] = (-1)*colour[u]; qu.push(v);
                }
                else{
                    if(colour[u] == colour[v]) return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    int G[][V] = {{0, 1, 0, 1},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
 
    isBipartite(G, 0) ? cout << "Yes" : cout << "No";
    return 0;
}
