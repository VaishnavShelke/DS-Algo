#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;

// Implementation of graph using Adjacency List
void addEdge(vector<int> adj[],int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int> adj[],int V){
    for(int i = 0; i < V ; i++){
        cout << "Adjancency List " << i << " ...\n Head ";
        for(int j = 0; j < adj[i].size(); j++){
            cout<< " -->> " << adj[i][j];
        }
        cout << "\n\n";
    }
}
int main(){
    int vertices = 5;
    vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj,vertices);
    return 0;
}
