#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;


// Detect cycle in Directed Graph
void DetectCycleDirected(vector<int> adj[], int start, int vertices){

    bool visited[vertices]; // Set all false initially
    stack<int> stak;

    for(int i = 0; i < vertices ; i++)  visited[i] = false;

    stak.push(start);
    visited[start] = true;
    int custody;

    while(!stak.empty()){
        custody = stak.top();
        stak.pop();


        for(int i = 0 ; i<adj[custody].size() ; i++){
            if(visited[adj[custody][i]] == false){
                stak.push(adj[custody][i]);
                visited[adj[custody][i]] = true;
            }
            if(visited[adj[custody][i]] == true){
                cout << "Cycle Detected .... \n";
                return;
            }
        }
    }
    cout << " No Cycle .............. ";
}

// Implementation of graph using Adjacency List
void addEdge(vector<int> adj[],int u, int v){
    adj[u].push_back(v);
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
    DetectCycleDirected(adj,0,vertices);
    //printGraph(adj,vertices);
    return 0;
}
