#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 10
#define _j first
#define _i second

// Why use visited all the time ??? ... Act smarter

void DFSBtrack(pair<int,int> base,pair<int,int> end,int dist,int mat[R][C],int& longestDist);
void findLongestPath(int mat[R][C],int st_j,int st_i,int ed_j,int ed_i){

    pair<int,int> start = {st_j,st_i};
    pair<int,int> end = {ed_j,ed_i};

    int longestDist = INT_MIN;
    mat[st_j][st_i] = -1;
    DFSBtrack(start,end,0,mat,longestDist);
    mat[st_j][st_i] = 1;

    cout << "The longest path distance is .... " << longestDist;
}

bool isValid(pair<int,int> next,int mat[R][C]){
    int j = next._j;
    int i = next._i;

    if( i<0 || j<0 || i>=C || j>=R || mat[j][i] == 0) return false;
    if(mat[j][i] == -1) return false;

    return true;

}

void DFSBtrack(pair<int,int> base,pair<int,int> end,int dist,int mat[R][C],int& longestDist){

    if(base._j == end._j && base._i == end._i){
        longestDist = max(longestDist,dist);
    }
    pair<int,int> steps[] = {{1,0},{0,1},{-1,0},{0,-1}};
    pair<int,int> next;

    for(int k = 0; k<4 ; k++){
        next._j = base._j + steps[k]._j;
        next._i = base._i + steps[k]._i;
        if(isValid(next,mat)){
            mat[next._j][next._i] = -1;
            DFSBtrack(next,end,dist+1,mat,longestDist);
            mat[next._j][next._i] = 1;
        }
    }
    return;

}

int main()
{
    int mat[R][C] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    };
 
    // find longest path with source (0, 0) and
    // destination (1, 7)
    findLongestPath(mat, 0, 0, 1, 7);
 
    return 0;
}
