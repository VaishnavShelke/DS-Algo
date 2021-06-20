#include<iostream>
#include <list>
#define NIL 99999
using namespace std;
 
// If the child's earliest contacts is ancestor { discovery time wise} of or is equal to the parent then the parent is 
// An articulation point
// Now espicially for root is the root has more than 1 children in our DFS graph the root also is AP

// Articulation Point in A Graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
    void APUtil(int v, bool visited[], int disc[], int low[],
                int parent[], bool ap[]);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void AP();    // prints articulation points
    void DFSBased(int* distTime,int* earliestCont,int* parent,int u,bool* artiPt);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}
 
void Graph::AP(){

    int* discTime = new int[V];
    int* earliestCont = new int[V];
    int* parent = new int[V];
    bool* artiPt = new bool[V];

    for(int i = 0; i<V; i++){
        discTime[i] = NIL; earliestCont[i] = NIL; parent[i] = i; artiPt[i] = false;
    }

    int randomU = 0;

    DFSBased(discTime,earliestCont,parent,randomU,artiPt);
    for(int i = 0; i<V; i++){
        if(artiPt[i]) cout << i << " ";
    }

}
 
void Graph:: DFSBased(int* discTime,int* earliestCont,int* parent,int u,bool* artiPt){
    
    static int timestamp = 0;
    int children = 0;
    discTime[u] = timestamp;
    earliestCont[u] = timestamp;
    timestamp++;
    int v;

    for(auto a = adj[u].begin(); a != adj[u].end() ; a++){
        v = *a;

        if(discTime[v] == NIL){
            parent[v] = u; children++;
            DFSBased(discTime,earliestCont,parent,v,artiPt);
            earliestCont[u] = min(earliestCont[v],earliestCont[u]);

            if(parent[u] != u && earliestCont[v] >= discTime[u]){             // These two conditions make all the difference between bridge and AP
                artiPt[u] = true;
            }
            if(parent[u] == u && children>1){
                artiPt[u] = true;
            }
        }
        else if(parent[u] != v){
            earliestCont[u] = min(discTime[v],earliestCont[u]);
        }
        
    }


}


int main()
{
    // Create graphs given in above diagrams
    cout << "\nArticulation points in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.AP();
 
    cout << "\nArticulation points in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.AP();
 
    cout << "\nArticulation points in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.AP();
 
    return 0;
}
