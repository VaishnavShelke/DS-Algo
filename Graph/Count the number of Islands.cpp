#include<iostream>
#include<bits\stdc++.h>
using namespace std;
#define dim 5
// Find The number of Islands



void DFS(pair<int,int> start,bool visited[][dim],int M[][dim]){

    if(start.first < 0 || start.first >=dim || start.second <0 || start.second>=dim) return;
    if(visited[start.first][start.second] == true || M[start.first][start.second] == 0) return;
    visited[start.first][start.second] = true;
    
    pair<int,int> steps[8] = {make_pair( 1, -1),make_pair( 1,  0),make_pair( 1, +1),make_pair(-1, -1),
                              make_pair(-1,  1),make_pair(-1,  0),make_pair( 0, -1),make_pair( 0, 1)};
    pair<int,int> next;
    for(int i = 0; i<8 ; i++){
        next = make_pair(start.first+steps[i].first,start.second + steps[i].second);
        DFS(next,visited,M);
    }
    
}


int countIslands(int M[][dim]){
    bool visited[dim][dim];
    int count = 0;
    for(int i = 0; i<dim ; i++){for(int j = 0; j<dim ; j++){visited[i][j] = false;}}

    for(int j = 0; j<dim ; j++){
        for(int i = 0; i<dim ; i++){
            if(!visited[j][i] && M[j][i] == 1) {count++;DFS(make_pair(j,i),visited,M);}
        }
    }
    return count;

}

int main()
{
    int M[dim][dim] =     { { 1, 1, 0, 0, 0 },
                            { 0, 1, 0, 0, 1 },
                            { 1, 0, 1, 1, 1 },
                            { 1, 0, 1, 1, 0 },
                            { 1, 0, 1, 0, 1 } };
    
    cout << "Number of islands is: " << countIslands(M);
 
    return 0;
}
