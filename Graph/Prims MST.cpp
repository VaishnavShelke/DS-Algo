#include<bits/stdc++.h>
#include <iostream>
#define V 5
using namespace std;

int finMinIndex(pair<int,int>* edgeLength,set<int>* inMST){
    int minima = INT_MAX;
    int index;
    for(int i = 0; i<V ; i++){
        if(edgeLength[i].first < minima && inMST->find(i) == inMST->end()) {index = i; minima = edgeLength[i].first;}
    }
    return index;
}
void primMST(int graph[][V]){
    int source = 0;
    pair<int,int> edgeLength[V];
    for(int i = 0; i<V ; i++) {edgeLength[i].first = INT_MAX; edgeLength[i].second = INT_MAX;}
    set<int> inMST; int candidate;
    inMST.insert(source);
    tuple<int,int,int> MST[V-1];int H = 0;int u;

    for(int v = 0; v<V ; v++) {
        if(graph[source][v] != 0){
            edgeLength[v].first = graph[source][v];
            edgeLength[v].second = source;
            }}
    while(inMST.size()<V){
        u = finMinIndex(&edgeLength[0],&inMST);
        inMST.insert(u);
        MST[H] = make_tuple(u,edgeLength[u].second,edgeLength[u].first);
        for(int v = 0; v<V ; v++) {
            if(graph[u][v] != 0){
                if(graph[u][v]<edgeLength[v].first){
                    edgeLength[v].first = graph[u][v];
                    edgeLength[v].second = u;
                }
            }
        }
        H++;
    }

    for(int i = 0; i<H ; i++){
        cout << get<0>(MST[i]) << " --->> " << get<1>(MST[i])  << " ===== " << get<2>(MST[i])<< endl ;
    }
    return;
}



int main() 
{ 
    /* Let us create the following graph 
        2 3 
    (0)--(1)--(2) 
    | / \ | 
    6| 8/ \5 |7 
    | / \ | 
    (3)-------(4) 
            9     */
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 
  
    // Print the solution 
    primMST(graph); 
  
    return 0; 
}


