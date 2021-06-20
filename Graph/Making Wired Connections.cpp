#include<iostream>
#include <list>
#include<vector>
#define NIL 99999
using namespace std;

class Graph{
private: 
    list<int>* adj; int V;
public:
    Graph(int data){
        this->V = data;  adj = new list<int>[V];
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void DFS(int u,bool* visited){

        for(auto v: adj[u]){
            if(!visited[v]){
                visited[v] = true;
                DFS(v,visited);
            }
        }
        return;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Graph compNet(n);

        for(int i = 0; i<connections.size() ; i++){
            compNet.addEdge(connections[i][0],connections[i][1]);
        }

        bool* visited = new bool[n];
        for(int i = 0; i<n ; i++){
            visited[i] = false;
        }
        int islands = 0;

        for(int i = 0; i<n; i++){
            if(!visited[i]){
                visited[i] = true;
                islands++;
                compNet.DFS(i,visited);
            }
        }

        if(n-1 > connections.size()){
            return -1;
        }
        else{
            return islands-1;
        }
    }
};
