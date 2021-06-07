
#include<iostream>
#include <list>
#include<queue>
#include <limits.h>
using namespace std;

// Check if a graph is tree or not

class Graph
{
    int V;   
    list<int> *adj; 
public:
    Graph(int V);  
    void addEdge(int v, int w);  
    bool isTree();   
};
  
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
  
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Add v to w’s list.
}
  
bool Graph:: isTree(){
    bool visited[V]; int parent[V];
    for(int i = 0; i<V ; i++) { parent[i] = i; visited[i] = false;}

    queue<int> qu; qu.push(0);
    int u;

    while(!qu.empty()){
        u = qu.front();
        visited[u] = true;
        qu.pop();

        for(auto child: adj[u]){
            if(parent[u] != child && visited[child] == true){
                return false;
            }
            else{
                if(parent[u] != child){
                    parent[child] = u;
                    qu.push(child);
                }
            }
        }
    }
    for(int i =  0; i<V; i++){
        if(visited[i] == false) return false;
    }
    return true;
}

int main()
{
    Graph g1(6);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
  
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
  
    return 0;
}
