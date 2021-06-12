
#include<iostream>
#include<list>

// Journey to moon HR


class Graph{
private:
    int vertex; 
public:
    list<int>* adj;
    Graph(int vertex){this->vertex = vertex; adj = new list<int>[vertex];}
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

void DFS(Graph* graph,int u,bool* visited,int* size){
    visited[u] = true;
    *size = 1 + *size;
    for(int v : graph->adj[u]){
        if(!visited[v]) DFS(graph,v,visited,size);
    }
    return;
}

int journeyToMoon(int n, vector<vector<int>> astronaut) {
    Graph graph(n);
    
    for(int i = 0; i<astronaut.size(); i++){
        graph.addEdge(astronaut[i][0], astronaut[i][1]);
    }
    
    bool visited[n];
    for(int i = 0; i<n ; i++) visited[i] = false;
    
    int size; vector<int> sizes;
    for(int i = 0; i<n; i++){
        size = 0;
        if(visited[i] == false){
            DFS(&graph,i,visited,&size);
        }
        sizes.push_back(size);
    }
    
    int count = 0;
    for(int i = 0 ; i<sizes.size(); i++){
        for(int j = i+1; j<sizes.size(); j++){
            count += sizes[i]*sizes[j];
        }
    }
    return count;
}
