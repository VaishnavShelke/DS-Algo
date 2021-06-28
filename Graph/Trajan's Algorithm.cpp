#include<iostream>
#include <list>
#include <stack>
#include <string>
using namespace std;

// Tarjan’s Algorithm to find Strongly Connected Components

class Graph
{
    int V;    
    list<int> *adj;   
    void SCCUtil(int u, int disc[], int low[],bool* inStack,stack<int>& stc,int& timestamp);
public:
    Graph(int V);   
    void addEdge(int v, int w);   
    void SCC();    
};
  
void Graph::SCC(){

    int dist[V];
    int low[V];
    bool inStack[V];
    for(int i = 0; i<V; i++){
        dist[i] = -1; low[i] = -1; inStack[i] = false;
    }
    int src = 0;
    int timestamp = 0;
    stack<int> stc;
    
    for(int i = 0; i<V ; i++) {
        if(dist[i] == -1) SCCUtil(0,dist,low,inStack,stc,timestamp);
    }

}


void Graph:: SCCUtil(int u,int* dist,int* low,bool* inStack,stack<int>& stc,int& timestamp){

    dist[u] = timestamp;
    low[u] = timestamp;
    timestamp++;
    inStack[u] = true;
    stc.push(u);

    for(int v : adj[u]){
        if(dist[v] == -1){
            SCCUtil(v,dist,low,inStack,stc,timestamp);
            low[u] = min(low[u],low[v]);
        }
        else{
            if(inStack[v]) low[u] = min(low[u],dist[v]);
        }
    }

    if(dist[u] == low[u]){
        while(stc.top() != u){
            inStack[stc.top()] = false;
            std::cout << stc.top() << " ";
            stc.pop();
        }
        inStack[stc.top()] = false;
        std::cout << stc.top() << " ";
        stc.pop();
        std::cout << endl;
    }

}


Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
  
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
 
// Driver program to test above function
int main()
{
    cout << "\nSCCs in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.SCC();
  
    cout << "\nSCCs in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.SCC();
  
    cout << "\nSCCs in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.SCC();
  
    cout << "\nSCCs in fourth graph \n";
    Graph g4(11);
    g4.addEdge(0,1);g4.addEdge(0,3);
    g4.addEdge(1,2);g4.addEdge(1,4);
    g4.addEdge(2,0);g4.addEdge(2,6);
    g4.addEdge(3,2);
    g4.addEdge(4,5);g4.addEdge(4,6);
    g4.addEdge(5,6);g4.addEdge(5,7);g4.addEdge(5,8);g4.addEdge(5,9);
    g4.addEdge(6,4);
    g4.addEdge(7,9);
    g4.addEdge(8,9);
    g4.addEdge(9,8);
    g4.SCC();
  
    cout << "\nSCCs in fifth graph \n";
    Graph g5(5);
    g5.addEdge(0,1);
    g5.addEdge(1,2);
    g5.addEdge(2,3);
    g5.addEdge(2,4);
    g5.addEdge(3,0);
    g5.addEdge(4,2);
    g5.SCC();
  
    return 0;
}
