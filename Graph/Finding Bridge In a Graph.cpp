#include<iostream>
#include <list>
#define NIL 99999
using namespace std;
 
// Similar approach as in case of Articulation point but only 2 differnce
// You need not worry about the root node just follow this logic
// If childs earliest contact is grater {NOT EQUAL TO} than fathers theN THE CHILD PARENT are a bridge

// Finding Bridge In a Graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void Bridge();    // prints articulation points
    void DFSBased(int* distTime,int* earliestCont,int* parent,int u);
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
 
void Graph::Bridge(){

    int* discTime = new int[V];
    int* earliestCont = new int[V];
    int* parent = new int[V];
    bool* artiPt = new bool[V];

    for(int i = 0; i<V; i++){
        discTime[i] = NIL; earliestCont[i] = NIL; parent[i] = i;
    }

    int randomU = 0;
    DFSBased(discTime,earliestCont,parent,randomU);

}
 
void Graph:: DFSBased(int* discTime,int* earliestCont,int* parent,int u){
    
    static int timestamp = 0;
    discTime[u] = timestamp;
    earliestCont[u] = timestamp;
    timestamp++;
    int v;

    for(auto a = adj[u].begin(); a != adj[u].end() ; a++){
        v = *a;

        if(discTime[v] == NIL){
            parent[v] = u; 
            DFSBased(discTime,earliestCont,parent,v);
            earliestCont[u] = min(earliestCont[v],earliestCont[u]);

            if(earliestCont[v]>discTime[u]){
                cout << u << " --->> " << v << endl;
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
    cout << "\nBridge in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.addEdge(4, 2);
    g1.Bridge();
 
    cout << "\nBridge in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.Bridge();
 
    cout << "\nBridge in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.Bridge();
 
    return 0;
}
