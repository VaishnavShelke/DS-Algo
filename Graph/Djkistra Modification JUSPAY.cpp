#include<iostream>
#include<list>
#include<limits.h>
using namespace std;

// Aman EEE JUSPAY
/*
* There are N cities and M roads between them,
* All cities have traffic lights that switch between R and W after time interval T
* I takes C time to go from a citi to next citi
* Car has to wait if signal is red
* find the min time required to reach the citi N from 1
*/

class Graph{
private:
    int V; 
    list<int>* adj;
public:
    Graph(int V) { this->V = V; adj = new list<int>[V+1];}
    
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void modifiedDjkistra(int src,int dest,int C, int T){

        int distance[V+1];
        int temp;
        bool included[V+1];
        for(int i = 0; i<= V; i++){
            distance[i] = INT_MAX;
            included[i] = false;
        }
        distance[src] = 0;
        int u;
        while(1){
            u = findMinIndex(distance,included);
            if(u == -1) break;
            included[u] = true;
            for(int v: adj[u]){
                if(!included[v]){
                    if((distance[u]+ C)/T % 2 == 0){
                        temp = distance[u] + C;
                    }
                    else{
                        temp = distance[u] + C + T - (distance[u] + C)%T;
                    }
                    if(v == dest) temp = distance[u]+ C;
                    distance[v] = min(distance[v],temp);
                }
            } 
        }
        cout << distance[dest];
    }


    int findMinIndex(int* distance,bool* included){
        int minima = INT_MAX;
        int index = -1;
        for(int i = 1; i<= V ; i++){
            if(included[i] == false && distance[i]<minima){
                minima = distance[i];
                index = i;
            }
        }
        return index;
    }
};

int main(){

    Graph citiMap(5);
    citiMap.addEdge(1,2);
    citiMap.addEdge(1,3);
    citiMap.addEdge(2,4);
    citiMap.addEdge(1,4);
    citiMap.addEdge(2,5);
    int C = 5;
    int T = 3;
    citiMap.modifiedDjkistra(1,5,5,3);

}
