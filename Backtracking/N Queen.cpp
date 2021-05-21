#include <iostream>
#include <bits\stdc++.h>

using namespace std;

// N Queens Problem

bool checkValidity(bool* board,int siz,int xbase,int y){
    
    for(int i = xbase; i>=0 ; i--){
        if(*(board + i + y*siz) == true) return false;
    }
    
    int j = y ,i = xbase;
    while(j>0 && i>0){
        if(*(board + i + j*siz) == true) return false;
        j--;i--;
    }
    j = y ;i = xbase;
    while(j<siz && i>0){
        if(*(board + i + j*siz) == true) return false;
        j++;i--;
    }
    return true;


}

bool NQueens(bool* board,int siz,int xbase){

    if(xbase >= siz){
        return true;
    }
    for(int j = 0; j<siz; j++){
        if(checkValidity(board,siz,xbase,j)){
            *(board + xbase + j*siz) = true;
            if(NQueens(board,siz,xbase+1)){
                return true;
            }
            *(board + xbase + j*siz) = false;
        }
    }
    return false;
}



int main(){
    int siz = 4;
    bool board[siz][siz];

    for(int j = 0; j<siz ; j++){
        for(int i = 0; i<siz ; i++){
            board[j][i] = false;
        }
    }
    if(NQueens(&board[0][0],siz,0)){
        cout << "Solution Found ....\n";
    }
   
    for(int j = 0; j<siz ; j++){
        for(int i = 0; i<siz ; i++){
            cout<< board[j][i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
