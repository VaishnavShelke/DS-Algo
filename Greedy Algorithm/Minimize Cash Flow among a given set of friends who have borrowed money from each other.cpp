#include<iostream>
#include<queue>
using namespace std;
 
#define N 4

class maxHeap{
public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.first<b.first;
    }
};

void minCashFlow(int graph[N][N]){

    int balance[N];
    for(int i = 0; i<N ; i++){
        balance[i] = 0;
    }

    for(int j = 0; j<N ; j++){
        for(int i = 0 ; i<N ; i++){
            balance[j] -= graph[j][i];
            balance[i] += graph[j][i];
        }
    }
   
    priority_queue<pair<int,int>,vector<pair<int,int>>,maxHeap> plus,minus;

    for(int i = 0; i<N ; i++){
        if(balance[i]>0){
            plus.push({balance[i],i});
        }
        if(balance[i]<0){
            minus.push({-balance[i],i});
        }
    }

    pair<int,int> ptop,mtop;
    while(!minus.empty()){
        if(minus.top()>plus.top()){
            cout << minus.top().second << " will give " << plus.top().second << " amount " << plus.top().first << endl;
            ptop = plus.top();  plus.pop();
            mtop = minus.top(); minus.pop();
            minus.push({mtop.first-ptop.first,mtop.second});
        }
        else if(minus.top()<plus.top()){
            cout << minus.top().second << " will give " << plus.top().second << " amount " << minus.top().first << endl;
            mtop = minus.top(); minus.pop();
            ptop = plus.top(); plus.pop();
            plus.push({ptop.first-mtop.first,ptop.second});
        }
        else{
            cout << minus.top().second << " will give " << plus.top().second << " amount " << minus.top().first << endl;
            plus.pop();minus.pop();
        }
    }
}

int main()
{
    // graph[i][j] indicates the amount that person i needs to
    // pay person j
    int graph[N][N] = { {0, 1000, 1000,0},
                        {0, 0, 0,1000},
                        {0, 0, 0,1000},
                        {0, 0, 0, 0}};
 
    // Print the solution
    minCashFlow(graph);
    re
