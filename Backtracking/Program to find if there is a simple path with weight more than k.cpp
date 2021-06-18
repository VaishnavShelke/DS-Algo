// Program to find if there is a simple path with
// weight more than k
#include<bits/stdc++.h>
using namespace std;
 
// iPair ==>  Integer Pair
typedef pair<int, int> iPair;
 
class Graph
{
    int V;    
    list< pair<int, int> > *adj;
 
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    bool pathMoreThanK(int src,int K); 
    void DFSBtrack(int u,int dist,bool *visited,int& maxDist);  
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
bool Graph::pathMoreThanK(int u,int K){
    bool visited[V];
    for(int i = 0; i<V ; i++) visited[i] = false;
    int maxDist = 0;
    visited[u] = true;
    DFSBtrack(u,0,visited,maxDist);
    if(maxDist > K) return true;
    else return false;
}

void Graph:: DFSBtrack(int u,int dist,bool* visited,int& maxDist){
    
    if(maxDist < dist){
        maxDist = dist;
    }

    int v;
    for(auto a: adj[u]){
        v = a.first;
        if(visited[v] == false){
            visited[v] = true;
            DFSBtrack(v,dist + a.second,visited,maxDist);
            visited[v] = false;
        }
    }
    return;
}

int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);
 
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    int src = 0;
    int k = 62;
    g.pathMoreThanK(src, k)? cout << "Yes\n" :
                             cout << "No\n";
 
    k = 60;
    g.pathMoreThanK(src, k)? cout << "Yes\n" :
                             cout << "No\n";
 
    return 0;
}
