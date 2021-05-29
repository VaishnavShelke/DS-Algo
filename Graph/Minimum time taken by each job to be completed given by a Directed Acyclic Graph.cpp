#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;


class  Graph{
private:
    int vertices; vector<int>* graph;
public:
    Graph(int vertices){ this->vertices = vertices+1; graph = new vector<int>[this->vertices];}
    void addEdge(int u,int v) {graph[u].push_back(v);}
    void DFSranking(int u,int rank,int* ranking);
    void printOrder(){
        // Search for the root nodes
        bool hasparent[this->vertices];
        int ranking[this->vertices];
        for(int i = 0; i<this->vertices ; i++) {hasparent[i] = false; ranking[i] = 0;}
        for(int u = 0; u<vertices ; u++){
            for(int v = 0 ; v<graph[u].size() ; v++){
                hasparent[graph[u][v]] = true;
            }
        } 
        for(int i = 0; i<vertices ; i++){
            if(hasparent[i] == false){
                DFSranking(i,0,&ranking[0]);
            }
        }
        for(int i = 1; i < vertices; i++) cout << ranking[i]+1 << " ";
    }
    void DFS(int u);
};
void Graph :: DFS(int u){
    static set<int> included;
    for(int v = 0; v< graph[u].size() ; v++){
        if(included.find(graph[u][v])==included.end()) DFS(graph[u][v]);
    }
    included.insert(u);
    cout << u << " --->> ";
}
void Graph :: DFSranking(int u,int rank,int* ranking){
    int parent = u;

    for(int v = 0; v<graph[u].size(); v++){
        DFSranking(graph[parent][v],rank+1,ranking);
    }
    ranking[parent] = max(ranking[parent],rank);
};




int main()
{
    // Given Nodes N and edges M
    int n, m;
    n = 10;
    m = 13;
 
    Graph graph(n);
    // Given Directed Edges of graph
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(1, 5);
    graph.addEdge(2, 3);
    graph.addEdge(2, 8);
    graph.addEdge(2, 9);
    graph.addEdge(3, 6);
    graph.addEdge(4, 6);
    graph.addEdge(4, 8);
    graph.addEdge(5, 8);
    graph.addEdge(6, 7);
    graph.addEdge(7, 8);
    graph.addEdge(8, 10);
 
    // Function Call
    graph.printOrder();
    return 0;
}
