#include <iostream>
#include <bits\stdc++.h>

using namespace std;

// Print elements in sorted order using row-column wise sorted array
/*
    Use of heap
    Same as mearging k sorted arrays
*/

int main(){
    int mat[4][4] = { {10, 20, 30, 40}, 
                    {15, 25, 35, 45}, 
                    {27, 29, 37, 48}, 
                    {32, 33, 39, 50}, };
    priority_queue<int,vector<int>,greater<int>> minheap;
    int pointers[4] = {};
    for(int j = 0; j<4 ; j++){
        minheap.push(mat[j][0]);
    }

    cout << "Row column wise sorted matrix in sorted order ... \n";
    int counter = 0;
    int totalnos = 16;
    int saturate = 0;
    while(saturate != 4){
        saturate = 0;
        for(int i = 0; i<4 ; i++){
            if(minheap.top() == mat[i][pointers[i]] && pointers[i]<4){
                pointers[i]++;
                cout << minheap.top() << " ";
                minheap.pop();
                if(pointers[i]<4)
                    minheap.push(mat[i][pointers[i]]);
            }
            if(pointers[i] == 4){
                saturate++;
            }
        }
    }
    return 0;
}
