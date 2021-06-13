#include <bits/stdc++.h>
using namespace std;
# define R 3
# define C 5

// Minimum time required to rot all oranges

bool isValid(pair<int,int> next,int v[R][C]){
    int j = next.first;
    int i = next.second;

    if(j<0 || i<0 || i>=C || j>= R){
        return false;
    }
    if(v[j][i] == 2 || v[j][i] == 0) return false;

    return true;
}

int rotOranges(int v[R][C]){

    queue<pair<int,int>> qu;

    int ones = 0;
    for(int j = 0; j<R ; j++){
        for(int i = 0; i<C ; i++){
            if(v[j][i] == 2){
                qu.push({j,i});
            }
            if(v[j][i] == 1){
                ones++;
            }
        }
    }
    
    qu.push({-1,-1});
    pair<int,int> steps[4] = {{1,0},{0,1},{-1,0},{0,-1}};
    pair<int,int> rotten,next;
    int frames = 0,iones = 0;
    while(!qu.empty()){

        if(qu.front().first == -1){
            qu.pop();
            if(qu.empty()) break;
            frames++;
            qu.push({-1,-1});
        }

        rotten = qu.front();
        qu.pop();
        
        for(int i = 0; i<4 ; i++){
            next = {rotten.first + steps[i].first, rotten.second + steps[i].second};
            if(isValid(next,v)){
                v[next.first][next.second] = 2;
                ones--;
                qu.push(next);
            }
        }

    }

    if(ones > 0) return INT_MAX;
    return frames;
    

}

int main()
{
 
    int v[R][C] = { { 2, 1, 0, 2, 1 },
                    { 0, 0, 1, 2, 1 },
                    { 1, 0, 1, 2, 1 } };
 
    cout  << "The frames required to rot all oranges ... " << rotOranges(v);
 
    return 0;
}
