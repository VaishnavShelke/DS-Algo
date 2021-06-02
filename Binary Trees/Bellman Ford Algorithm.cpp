#include <iostream>
#include <bits\stdc++.h>

using namespace std;


// Bell Man Ford Algorithm
// The order of feeding edges doesnt matter
/**
 * !                   YOU CAN INPUT EDGES IN ANY ORDER YOU WANT                      
 * !                   UNLIKE DJKASTRA IT CAN HANDLE NEGATIVE WTS                     
 * !           BUT THE ALGORITHM IS INEFFICTIVE WHEN NEGATIVE WEIGHT CYCLE PRESENT    
 **/

int main(){
    int graph[][5] = {{ 0, -1, 4, 0, 0},
                      { 0, 0, 3, 2 ,2},
                      { 0, 0, 0, 0, 0},
                      { 0, 1, 5, 0, 0},
                      { 0, 0, 0, -3, 0}};
    int source = 0;
    vector<pair<int,int>> allPairs;

    for(int j = 0; j<5 ; j++){
        for(int i = 0; i<5 ; i++){
            if(graph[j][i] != 0) allPairs.push_back(make_pair(j,i));
        }
    }

    int u,v;
    int distance[5];
    for(int i = 0; i<5 ; i++){
        distance[i] = INT_MAX;
    }
    distance[source] = 0;

    for(int times = 0; times<5 - 1; times++){
    for(int i = 0; i<allPairs.size() ; i++){
        u = allPairs[i].first;
        v = allPairs[i].second;
        if(distance[u] != INT_MAX && distance[u] + graph[u][v]<distance[v])
         distance[v] = distance[u] + graph[u][v];
    }
    }

    for(int i = 0; i<5 ;i++){
        cout << i << " ---> " << distance[i] << endl;
    }
    return 0;
}
