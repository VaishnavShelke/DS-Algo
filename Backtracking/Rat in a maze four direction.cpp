#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define width 5
#define height 5
// Rat in a Maze
/*
    The rat starts from the point (0,0) find the path of the rat to reach the bottom-right.
    The rat can move up-right-down-left
*/
bool pathexists(int col,int row,bool visited[][width],bool maps[][width],vector<pair<int,int>>* str,pair<int,int>* directions);
bool permissionlepehle(int col,int row,bool visited[][width],bool maps[][width]);
int main(){
    vector<pair<int,int>> str ;
    bool maps[][width] = {      { 1, 0, 0, 0, 0 },
                                { 1, 1, 1, 1, 1 },
                                { 1, 1, 1, 0, 1 },
                                { 0, 0, 0, 0, 0 },
                                { 0, 0, 0, 0, 1 } };

    bool visited[height][width] = {};
    pair<int,int> directions[] = {make_pair(1,0),make_pair(0,1),make_pair(-1,0),make_pair(0,-1)};
    map<pair<int,int>,char> disha;
    disha[directions[0]] = 'R';
    disha[directions[1]] = 'D';
    disha[directions[2]] = 'L';
    disha[directions[3]] = 'U';
    bool got_it = pathexists(0,0,visited,maps,&str,directions); 
    int sizevec = str.size();
    if (got_it){
    for(int i = 0; i<str.size(); i++){
         cout<< disha[str[sizevec-1-i]] << " ";
    }}
    else cout << "Not possible";
    return 0;
}

bool permissionlepehle(int col,int row,bool visited[][width],bool maps[][width]){
    if(row == height -1 && row == width-1 && maps[col][row]) return true;
    if(col < width && row < height && !visited[row][col] && maps[row][col] && row>=0 && col>=0)
        return true;
    else  return false;
}
bool pathexists(int col,int row,bool visited[][5],bool maps[][5],vector<pair<int,int>>* str,pair<int,int>* directions){
    
    if(row == height-1 && col == width-1 && permissionlepehle(col,row,visited,maps)) return true;
    if(!permissionlepehle(col,row,visited,maps)){
        return false;
    }
    bool sucess = false;
    visited[row][col] = true;
    for(int i = 0; i<4 ; i++){
        if(pathexists(col + directions[i].first,row + directions[i].second,visited,maps,str,directions)){
            //cout << row << " " << col << "\n";
            str->push_back(directions[i]);
            sucess = true;
        }
    }
    if(!sucess) return false;
    else return true;
                                        
}
