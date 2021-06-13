#include <bits/stdc++.h>
using namespace std;
# define N 3
# define M 4

// Distance of nearest cell having 1 in a binary matrix

bool isValid(pair<int,int> next, int distMin[N][M]){
    int j = next.first;
    int i = next.second;

    if( i<0 || j<0 || i>=M || j>= N){
        return false;
    }
    if(distMin[j][i] == INT_MAX){
        return true;
    }
    return false;
}

void printDistance(int mat[N][M]){

    int distMin[N][M];
    queue<pair<int,int>> qu;
    pair<int,int> cord, next;
    pair<int,int> steps[4] = {{0,1},{1,0},{-1,0},{0,-1}};

    for(int j = 0; j<N ; j++){
        for(int i = 0; i<M ; i++){
            distMin[j][i] = INT_MAX;
            if(mat[j][i] == 1) {
                distMin[j][i] = 0;
                qu.push({j,i});
            }
        }
    }

    while(!qu.empty()){
        cord = qu.front();
        qu.pop();
        
        for(int i = 0 ; i<4; i++){
            next = {cord.first + steps[i].first,cord.second + steps[i].second};
            if(isValid(next,distMin)){
                qu.push(next);
                distMin[next.first][next.second] = distMin[cord.first][cord.second] + 1;
            }
        }

    }

    for(int j = 0; j<N ; j++){
        for(int i = 0; i<M ; i++){
            cout << distMin[j][i] << " ";
        }
        cout << endl;
    }

}


int main()
{
    int mat[N][M] =
    {
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 1, 0, 0
    };
 
    printDistance(mat);
 
    return 0;
}
