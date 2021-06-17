#include <bits/stdc++.h>
using namespace std;
#define R 12
#define C 10
// Find shortest safe route in a path with landmines

bool isSafe(int j,int i,int mat[R][C],bool visited[R][C]){
    if(i<0 || j<0 || i>=C || j>=R){
        return false;
    }
    if(visited[j][i]) return false;
    if(mat[j][i] == 0) return false;

    pair<int,int> steps[] = {{1,0},{0,1},{-1,0},{0,-1}};
    int next_j,next_i;
    for(int k = 0; k<4 ; k++){
        next_j = j + steps[k].first;
        next_i = i + steps[k].second;    
        if(next_i>=0 && next_j>=0 && next_i<C && next_j<R && mat[next_j][next_i] == 0){
            return false;
        }    
    }
    return true;
}

void myfindShortestPath(int mat[R][C],int j,int i,vector<pair<int,int>> path,int* shortP,bool visited[R][C]){

    if(i == C-1){
        if(*shortP > path.size()){
            *shortP = path.size();
            for(pair<int,int> a: path){
                cout << "( " << a.first << ", " << a.second<< ")";
            }
            cout << endl;
        }
        return;
    }
    static pair<int,int> steps[] = {{1,0},{0,1},{-1,0},{0,-1}};
    int next_j,next_i;

    for(int k = 0; k<4 ; k++){
        next_j = j + steps[k].first;
        next_i = i + steps[k].second;
        if(isSafe(next_j,next_i,mat,visited)){
            visited[next_j][next_i] = true;
            path.push_back({next_j,next_i});
            myfindShortestPath(mat,next_j,next_i,path,shortP,visited);
            path.pop_back();
            visited[next_j][next_i] = false;
        }
    }
    return;
}
void findShortestPath(int mat[R][C]){

    int shortP = INT_MAX;
    bool visited[R][C];
    for(int j = 0 ; j<R ; j++){
        for(int i = 0; i<C ; i++){
            visited[j][i] = false;
        }
    }
    vector<pair<int,int>> path;
    for(int j = 0; j<R ; j++){
        if(isSafe(j,0,mat,visited)){
            visited[j][0] = true;
            path.push_back({j,0});
            myfindShortestPath(mat,j,0,path,&shortP,visited);
            path.pop_back();
            visited[j][0] = false;
        }
    }
    cout << "The shortest path length is ... " << shortP-1;
}
int main()
{
    // input matrix with landmines shown with number 0
    int mat[R][C] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };
 
    // find shortest path
    findShortestPath(mat);
 
    return 0;
}
