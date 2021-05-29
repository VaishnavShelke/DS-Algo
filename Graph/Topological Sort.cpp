#include<iostream>
#include<bits\stdc++.h>
using namespace std;

// Topological Sort
class Graph{
private:
    int vertex;
    vector<int>* llist;
public:
    void DFS(int i, stack<int>* stc,bool* visited);
    Graph(int vertex){ this->vertex = vertex; llist = new vector<int>[vertex];}
    void addEdge(int u,int v){
        llist[u].push_back(v); return;
    }
    void topologicalSort(){
        stack<int> stc;
        bool visited[vertex];
        for(int i = 0; i<vertex ; i++){visited[i] = false;}
        bool bol;
        for(int u = 0; u<vertex ; u++){
            this->DFS(u,&stc,&visited[0]);
        }
        while(!stc.empty()) {cout << stc.top() << " --->> "; stc.pop();}
    }
};

void Graph :: DFS(int u,stack<int>* stc,bool* visited){
    
    if(visited[u]) return;
    for(int v = 0; v<llist[u].size() ; v++){
        DFS(llist[u][v],stc,visited);
    }
    stc->push(u);
    visited[u] = true;
}



// Driver Code
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given "
            "graph \n";
 
    // Function Call
    g.topologicalSort();
 
    return 0;
}
