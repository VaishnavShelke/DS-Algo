#include<iostream>
#include<bits\stdc++.h>
using namespace std;

// Djkistra Shortest Path Algorithm

int findmin(int *DISTSOURCE,int vertex,bool* visited){
    int minima = INT_MAX;
    int index;
    for(int i = 0; i<vertex; i++){
        if(DISTSOURCE[i] < minima && visited[i] == false){
            minima = DISTSOURCE[i]; index = i;
        }
    }
    return index;
}
void dijkstra(int* graph,int source,int vertex){
    int DISTSOURCE[vertex];
    bool visited[vertex];
    for(int i = 0; i<vertex ; i++) {DISTSOURCE[i] = INT_MAX; visited[i] = false;}
    DISTSOURCE[source] = 0; 
    int u;

    for(int count  = 0; count < vertex; count++){
        u = findmin(&DISTSOURCE[0],vertex,&visited[0]);
        //cout << "\n" << u;
        visited[u] = true;
        
        for(int v = 0; v<vertex; v++){
            if(*(graph + u*vertex + v) && !visited[v] && DISTSOURCE[v] > DISTSOURCE[u] + *(graph + u*vertex + v))
                DISTSOURCE[v] = DISTSOURCE[u] + *(graph + u*vertex + v);
        }
    }

    for(int i = 0; i<vertex ; i++){
        cout << i << " ---->> " << DISTSOURCE[i] << endl;
    }
    return;

    
}
int main()
{
    /* Let us create the example graph discussed above */
    int graph[][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
  
    dijkstra(&graph[0][0], 0,9);
  
    return 0;
}
