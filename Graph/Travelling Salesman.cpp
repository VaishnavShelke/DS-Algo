#include <iostream>
#include <bits\stdc++.h>

using namespace std;

/**
 * !                   HAMILTON CYCLE OR TRAVELLING SALESMAN PROBLEM                
 *  
 * ? General Formulae                   shortestpathfrom_a to remaining  = min  { dist[a][rem[i]] + SPF rem[i] to {remaining - rem[i]}}
 **/

int SPF_CurrtoRemaining(int current,set<int>* unvisited,vector<int>* path,int* map,int towns,int source){

    if(unvisited->size() == 0) return *(map + current*towns + source) ;
    int cost ; int Minima =99999;
    int temp;
    vector<int> vect;
    for(auto a : *unvisited){
        vect.push_back(a);
    }
    for(auto a: vect){
        unvisited->erase(a);
        
        cost = *(map + current*towns + a) + SPF_CurrtoRemaining(a,unvisited,path,map,towns,source);
        
        if(cost<Minima){
            temp = a;
            Minima = cost;
        }
        unvisited->insert(a);
    }
    path->push_back(temp);
    return Minima;   
}
int main(){
    int towns = 4;
    int map[][towns] = {{ 0, 10, 15, 20},
                    { 5, 0, 9, 10},
                    { 6, 13, 0, 12},
                    { 8, 8, 9, 0}};

    set<int> unvisited;
    int start = 0;
    for(int i = 0 ; i<towns ; i++) if(i != start) unvisited.insert(i);
    vector<int> path;
    int cost;
    cost = SPF_CurrtoRemaining(start,&unvisited,&path,&map[0][0],towns,start);
    
    cout << "The Salesman Path is ...\n";
    for(int i = 0; i<path.size(); i++){
        cout << path[i] << " ---> ";
    }
    cout << "          " << cost;
    return 0;

}
