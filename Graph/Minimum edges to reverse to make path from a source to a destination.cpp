//C++ code for reversing a queue
#include <bits/stdc++.h>
using namespace std;
#define INF 99999

class Graph{
private:
    int V; 
    list<pair<int,int>>* adj;
public:
    Graph(int V){
        this->V = V; adj = new list<pair<int,int>>[V];
    }

    void addEdge(int u,int v){
        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
    }
 
    int minDistNodeFind(int* distFromS,bool* visited){
        int minima = INT_MAX;
        int index = -1;
        for(int i = 0; i<V ; i++){
            if(visited[i] == false && distFromS[i]<minima){
                minima = distFromS[i];
                index = i;
            }
        }
        return index;
    }

    int dkjistra(int src,int dest){

        int distFromS[V];
        bool visited[V];
        for(int i = 0; i<V ; i++) { distFromS[i] = INF; visited[i] = false;}
        distFromS[src] = 0;

        int u;
        while(true){
            u = minDistNodeFind(distFromS,visited);
            if(u == -1) break;
            visited[u] = true;

            for(pair<int,int> v : adj[u]){
                    
                distFromS[v.first] = min( distFromS[u] + v.second, distFromS[v.first]);
                
            }
        }
        return distFromS[dest];
    }

};

int getMinEdgeReversal(int edge[][2], int E,int V,int src,int dst){

    Graph tree(V);

    for(int i = 0; i<E ; i++){
        tree.addEdge(edge[i][0],edge[i][1]);
    }
    int answer = tree.dkjistra(src,dst);
    if(answer == INF) return -1;
    return answer;
}

//  Driver code to test above method
int main()
{
    int V = 7;
    int edge[][2] = {{0, 1}, {2, 1}, {2, 3}, {5, 1},
                     {4, 5}, {6, 4}, {6, 3}};
    int E = sizeof(edge) / sizeof(edge[0]);
 
    int minEdgeToReverse =
                  getMinEdgeReversal(edge, E, V, 0, 6);
    if (minEdgeToReverse != -1)
        cout << minEdgeToReverse << endl;
    else
        cout << "Not possible" << endl;
    return 0;
}
