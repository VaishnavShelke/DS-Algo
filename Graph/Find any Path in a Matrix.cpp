#include <iostream>
#include <bits\stdc++.h>

using namespace std;

// DFS search for path(need not be shortest)

bool DFSearch(int i, int j,int* map,bool* visited,int wd,int ht,vector<pair<int,int>>* path){

    if(i == wd-1,j == ht - 1){
        path->push_back(make_pair(i,j));
        return true;
    }

    if(i < 0 || j < 0 || i >= wd || j>= ht)
        return false;

    if(*(map + i + j*wd) == 0 || *(visited + i + j*wd) == true)
        return false;


    *(visited + i + j*wd) = true;

    if(DFSearch(i+1,j,map,visited,wd,ht,path)){
        path->push_back(make_pair(i,j));
        return true;
    }
    if(DFSearch(i,j+1,map,visited,wd,ht,path)){
        path->push_back(make_pair(i,j));
        return true;
    }
    if(DFSearch(i-1,j,map,visited,wd,ht,path)){
        path->push_back(make_pair(i,j));
        return true;
    }
    if(DFSearch(i,j-1,map,visited,wd,ht,path)){
        path->push_back(make_pair(i,j));
        return true;
    }

    *(visited + i + j*wd) = false;
    return false;
}



int main(){
    int map[][6] = {
            {1, 0, 0, 0 ,0 ,0},
            {1, 0, 1, 1 ,1 ,0},
            {1, 0, 1, 0 ,1 ,0},
            {1, 1, 1, 0 ,1 ,0},
            {1, 0, 0, 0 ,1 ,1},
            {1, 1, 1, 1 ,0 ,1}};
    
    int ht = 6, wd = 6;
    bool visited[ht][wd];
    vector<pair<int,int>> path;
    for(int j = 0; j<ht ; j++){
        for(int i = 0; i<wd ; i++){
            visited[j][i] = false;
        }
    }

    if(DFSearch(0, 0, &map[0][0], &visited[0][0], wd, ht, &path));
    {
        cout << "Path Exists and the path is ....\n Start ";
        for(int i = path.size() - 1 ; i>=0 ; i--){
            cout << " -->> ( " << path[i].first << ", " << path[i].second << " )";
        }
    }

    return 0;
}
