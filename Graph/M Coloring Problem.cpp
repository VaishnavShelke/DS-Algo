#include <iostream>
using namespace std;
 
#define V 4

// M colouring Problem
 
bool isSafe(bool graph[V][V],int v,int c,int* colour){

    for(int i = 0; i<V; i++){
        if(graph[v][i] == true){
            if(colour[i] == c){
                return false;
            }
        }
    }
    return true;
}

bool Btrack(bool graph[V][V],int m,int src,int incl,int* colour){

    int v;
    if(incl == V){
        for(int i = 0; i<V ; i++) cout << colour[i] << " ";
        return true;
    }

    for(int v = 0; v<V; v++){
        if(graph[src][v] == true && colour[v] == -1){
            for(int c = 1; c<= m ; c++){
                if(isSafe(graph,v,c,colour)){
                    colour[v] = c;
                    if(Btrack(graph,m,v,incl+1,colour)){
                        return true;
                    }
                    colour[v] = -1;
                }
            }
        }
    }
    return false;
}

void graphColouring(bool graph[V][V],int m){

    int* colour = new int[V];
    for(int i = 0; i<V ; i++){
        colour[i] = -1;
    } 
    bool canBeColoured = false;
    int src = 0;
    for(int i = 1; i<=m ; i++){
        colour[src] = i;
        canBeColoured = Btrack(graph,m,src,1,colour);
        colour[src] = -1;
        if(canBeColoured) { cout << " Graph can Be coloured "; return;}
    }
    cout << " Graph Cannot Be coloured";
    return;
}

int main()
{
     
    /* Create following graph and test
       whether it is 3 colorable
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
    bool graph[V][V] = { { 0, 1, 1, 1 },
                         { 1, 0, 1, 1 },
                         { 1, 1, 0, 1 },
                         { 1, 1, 1, 0 }, };
                          
    // Number of colors
    int m = 3;
    graphColouring(graph, m);
    return 0;
}
