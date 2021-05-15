#include <iostream>
#include <bits\stdc++.h>

using namespace std;

bool bounds(int x,int y,int ht,int wd,int initcol,int* screen){
    if( x<0 || y<0 || x>=wd || y>=ht){
        return false;
    }
    if(initcol == *(screen + x + y*wd)){
        return true;
    }
    return false;
}
void replaceColourAt(int x,int y,int* screen,int ht,int wd,int fincol){

    pair<int,int> steps[] = {make_pair(+1,+1),make_pair(+1, 0),make_pair(+1,-1),make_pair( 0,-1),
                            make_pair(-1,+1),make_pair(-1, 0),make_pair(-1,-1),make_pair( 0,+1)};
    bool visited[ht][wd];
    for(int j = 0; j<ht ; j++){
        for(int i = 0; i<wd ; i++){
            visited[j][i] = false;
        }
    }

    queue<pair<int,int>> qu;
    int childx,childy;
    qu.push(make_pair(x,y));
    pair<int,int> parent;
    int initcol = *(screen + x + y*wd);
    visited[x][y] = true; 
    *(screen + x + y*wd) = fincol;

    while(!qu.empty()){
        parent = qu.front();
        qu.pop();

        for(int i = 0; i<8 ; i++){
            childx = parent.first + steps[i].first;
            childy = parent.second + steps[i].second;
            if(bounds(childx,childy,ht,wd,initcol,screen) && visited[childx][childy] == false){
                qu.push(make_pair(childx,childy));
                visited[childx][childy] = true;
                *(screen + childx + childy*wd) = fincol;
            }
        }
    }
    return;
}


 
int main(){

    int wd = 8,ht = 8;
    int screen[ht][wd]={{1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 0, 0, 1, 1, 0, 1, 1},
                        {1, 2, 2, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 2, 2, 0},
                        {1, 1, 1, 1, 1, 2, 1, 1},
                        {1, 1, 1, 1, 1, 2, 2, 1},
                        };
    
    for(int j = 0; j<ht ; j++){
        for(int i = 0; i<wd ; i++){
            cout << screen[j][i] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
    replaceColourAt( 5, 1,&screen[0][0],ht , wd, 9);
    for(int j = 0; j<ht ; j++){
        for(int i = 0; i<wd ; i++){
            cout << screen[j][i] << " ";
        }
        cout << "\n";
    }
}

