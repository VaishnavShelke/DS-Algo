#include<bits/stdc++.h>
using namespace std;
#define R 2
#define C 3

// Print all possible paths from top left to bottom right of a mXn matrix

bool isValid(pair<int,int> next,int ht,int wd){
    int j = next.first;
    int i = next.second;
    if( i<0 || j<0 || i==wd || j==ht) return false;
    return true;
}
void myPrintAllPaths(int* mat,pair<int,int> pos,int ht,int wd,vector<int>& path){

    if(pos.first == ht-1 && pos.second == wd-1){
        path.push_back(*(mat + wd*pos.first + pos.second));
        for(int i = 0; i<path.size() ; i++){
            cout << path[i] << " ";
        }
        cout << endl;
        path.pop_back();
        return;
    }

    pair<int,int> steps[] = {{1,0},{0,1}};
    pair<int,int> next;
    for(int i = 0; i<2 ; i++){
        next.first = pos.first + steps[i].first;
        next.second = pos.second + steps[i].second;
        if(isValid(next,ht,wd)){
            path.push_back(*(mat + wd*next.first+next.second));
            myPrintAllPaths(mat,next,ht,wd,path);
            path.pop_back();
        }
    }
}

void printAllPaths(int *mat,int ht,int wd){
    vector<int> path;
    path.push_back(*(mat));
    myPrintAllPaths(mat,{0,0},ht,wd,path);
}
int main()
{
    int mat[2][3] = { {1, 2, 3}, {4, 5, 6} };
    printAllPaths(*mat, 2, 3);
    return 0;
}
