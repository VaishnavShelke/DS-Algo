#include <iostream>
#include <bits\stdc++.h>
using namespace std;


// Check Negative Cycle Using Bellman Ford
/*
  Logic Behind Bellman ford
    A graph is approachable from at max V-1 directions if any Node has V-1 edges
    Hence we have to check for all directions hence V-1 times.
*/

struct Edge {
    int src, dest, weight;
};
 

struct Graph {
    int V, E;
    struct Edge* edge;
};
 

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[graph->E];
    return graph;
}
 
bool isNegCycleBellmanFord(Graph* graph,int source){

    int distfromSource[graph->V];
    for(int i = 0; i<graph->V ; i++) distfromSource[i] = INT_MAX;
    distfromSource[source] = 0;
    int dest; int start; int cost;
    for(int times = 0; times<graph->V ; times++){
        for(int line = 0; line < graph->E ; line++ ){
            dest = graph->edge[line].dest;
            start = graph->edge[line].src;
            cost = graph->edge[line].weight;
            if(distfromSource[start] != INT_MAX && distfromSource[dest] > distfromSource[start] + cost){
                distfromSource[dest] = distfromSource[start] + cost;
                if(times == graph->V-1) return true;
            }
        }
    }
    return false;
}

int main()
{
    int V = 5;
    int E = 8; 
    struct Graph* graph = createGraph(V, E);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
 

    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;
 
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;
 
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;
 
    if (isNegCycleBellmanFord(graph, 0))
        cout << "Yes";
    else
        cout << "No";
 
    return 0;
}
