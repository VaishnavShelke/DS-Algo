#include <bits/stdc++.h>
using namespace std;
 
// Specify number of rows and columns
#define M 4
#define N 5
#define INF 9696

void printCommonElements(int mat[M][N]){

    unordered_map<int,int> present;
    for(int i = 0; i<N ; i++){
        if(present.find(mat[0][i]) == present.end()){
            present[mat[0][i]] = 0;
        }
    }

    for(int j = 1; j<M ; j++){
        for(int i = 0; i<N ; i++){
            if(present.find(mat[j][i]) != present.end()){
                if(present[mat[j][i]] == j-1){
                    present[mat[j][i]] = j;
                }
                else{
                    present.erase(mat[j][i]);
                }
            }
        }
    }

    for( auto it = present.begin() ; it != present.end() ; it++){
        if((*it).second == M-1){
            cout << (*it).first << " ";
        }
    }
    return;
    
}
// driver program to test above function
int main()
{
    int mat[M][N] =
    {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {0, 0, 2, 7, 9},
    };
 
    printCommonElements(mat);
 
    return 0;
}
