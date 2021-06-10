#include <iostream>
#include <bits\stdc++.h>
using namespace std;

// Finding Longest Path in Directed Acyclic Graph
class AdjListNode {
public:
	int v;
	int weight;
	AdjListNode(int _v, int _w)
	{
		v = _v;
		weight = _w;
	}
};

class Graph {
	int V; 

	list<AdjListNode>* adj;


public:
	Graph(int V); 
	~Graph(); 
	void addEdge(int u, int v, int weight);
    void longestPath(int s);
    void longestPathEfficient(int s);
    int* topologicalSort();
    void DFS(int u,bool* inStack,stack<int>& stc);
};

Graph::Graph(int V) // Constructor
{
	this->V = V;
	adj = new list<AdjListNode>[V];
}

Graph::~Graph() // Destructor
{
	delete [] adj;
}

void Graph::addEdge(int u, int v, int weight)
{
	AdjListNode node(v, weight);
	adj[u].push_back(node); // Add v to u's list
}

void Graph :: longestPath(int s){
    int distanceFromS[V];
    for(int i = 0; i<V ; i++){
        distanceFromS[i] = INT_MIN;
    }
    distanceFromS[s] = 0;

    queue<int> qu;
    qu.push(s);
    int u;

    while(!qu.empty()){
        u = qu.front();
        qu.pop();

        for(auto child: adj[u]){
            if(distanceFromS[u] != INT_MIN && distanceFromS[child.v] < distanceFromS[u] + child.weight){
                distanceFromS[child.v] = distanceFromS[u] + child.weight;
            }
            qu.push(child.v);
        }
    }

    for(int i = 0; i<V ; i++){
        if(distanceFromS[i] == INT_MIN){
            distanceFromS[i] = INT_MAX;
        }
    }
    for(int i = 0; i<V ; i++){
        if(distanceFromS[i] != INT_MAX) cout << distanceFromS[i] << " ";
        else cout << "INF ";
    }

}

int* Graph:: topologicalSort(){
    int* intopologicalOrder = new int[V];
    bool inStack[V];
    for(int i = 0; i<V; i++) inStack[i] = false;
    stack<int> stc;
    for(int i = 0; i<V; i++){
        if(inStack[i] == false){
            DFS(i,inStack,stc);
        }    
    }

    for(int i = 0; i< V; i++){
        intopologicalOrder[i] = stc.top();
        stc.pop();
    }
     
    return intopologicalOrder;

}
void Graph :: DFS(int u,bool* inStack,stack<int>& stc){

    if(inStack[u] == true) return;
    for(auto a: adj[u])
        DFS(a.v,inStack,stc);
    stc.push(u);
    inStack[u] = true;
}

void Graph :: longestPathEfficient(int s){
    // We cannot use Djkistra Longest Path algorithm
    // Because can imagine a case..... when it fails

    // By finding the distance of children from itself and adding it to its source will do
    // In BFS lets say that a node v is visited, so all the distance of its child node are found relative to
    // dist[v] but due to nature of BFS if later a much longer dist[v] is found we will have to update 
    // all childrens of V again..., but in case of traversing in topological order *rather than BFS
    // if V is reached that means all the parents of V are aready traversed and this distance of v dist[v]
    // is already the longest
    int* topology;
    topology = topologicalSort(); int u,v;
    int distfromSource[V];
    for(int i = 0; i<V ; i++) distfromSource[i] = INT_MIN;
    distfromSource[s] = 0;

    for(int i = 0; i<V ; i++){
        u = topology[i];
        for(auto a: adj[u]){
            if(distfromSource[u] != INT_MIN && distfromSource[a.v] < distfromSource[u] + a.weight)
                distfromSource[a.v] = distfromSource[u] + a.weight;
        }
    }

    for(int i = 0; i<V ; i++){
        if(distfromSource[i] == INT_MIN) cout << "INF ";
        else cout << distfromSource[i] << " ";
    }
} 

int main()
{
	// Create a graph given in the above diagram.
	// Here vertex numbers are 0, 1, 2, 3, 4, 5 with
	// following mappings:
	// 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
	Graph g(6);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 3);
	g.addEdge(1, 3, 6);
	g.addEdge(1, 2, 2);
	g.addEdge(2, 4, 4);
	g.addEdge(2, 5, 2);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 5, 1);
	g.addEdge(3, 4, -1);  
	g.addEdge(4, 5, -2);

	int s = 1;
	cout << "Following are longest distances from "
			"source vertex "
		<< s << " \n";
	g.longestPath(s);
    cout << "\nWith More efficient approach ... \n";
    g.longestPathEfficient(s);

	return 0;
}
