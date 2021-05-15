#include <iostream>
#include <bits\stdc++.h>

using namespace std;

// Minimum Steps By knight to reach the destination
// And also teh path taken



class BFSlineagetree{
    public:
    pair<int,int> location;
    BFSlineagetree* parent = NULL;
    BFSlineagetree* makeConnection(pair<int,int> coordinate,BFSlineagetree* par);
};

class BFSlineagetree:: BFSlineagetree* makeConnection(pair<int,int> coordinate,BFSlineagetree* par){
    BFSlineagetree* temp = new BFSlineagetree;
    temp->location = coordinate;
    temp->parent = par;
    return temp;
};

bool bounds(int i, int j){
    if(i<0 || j<0 || i>=8 || j>= 8){
        return false;
    }
    return true;
}



BFSlineagetree* MinKnightPath(int fini, int finj){
    
    bool visited[8][8];
    for(int i = 0;i<8; i++){
        for(int j = 0; j<8; j++){
            visited[j][i] = false;
        }
    }
    queue<BFSlineagetree*> qu;
    BFSlineagetree* Dad  = makeConnection(make_pair(0,0),NULL);
    qu.push(Dad);
    visited[0][0] = true;
    BFSlineagetree* Son;
    pair<int,int> steps[] = {make_pair(-1,+2),make_pair(-1,-2),make_pair(+1,+2),make_pair(+1,+2),make_pair(+2,-1),make_pair(+2,+1),make_pair(-2,+1),make_pair(-2,-1)};
    int childx,childy;
    while(!qu.empty()){
        Dad = qu.front();
        qu.pop();
        for(int i = 0; i<8 ; i++){
                childx = Dad->location.first + steps[i].first;
                childy = Dad->location.second + steps[i].second;
                if(bounds(childx,childy) && visited[childx][childy] == false){
                    Son = makeConnection(make_pair(childx,childy),Dad);
                    qu.push(Son);
                    visited[childx][childy] = true;
                    if(childx == fini && childy == finj){
                        return Son;
                    }
                }
            }
    }
    return NULL;
}

int main(){
    BFSlineagetree* Son = MinKnightPath(1,0);
    int Chessboard[8][8] = {{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},};
    BFSlineagetree* current = Son;
    cout << "The shortest path is ... \n\n";
    while(current!=NULL){
        cout << " -->> ( " << current->location.first << ", " << current->location.second << ")"; 
        current = current->parent;
    }
    return 0;
}

