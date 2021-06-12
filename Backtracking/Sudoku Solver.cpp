#include <bits/stdc++.h>
using namespace std;
# define N 9
// Sudoku Solver

bool isValid(int number, int board[N][N],int position){
    int x = position%9;
    int y = position/9;
 

    for(int i = 0; i<N ; i++){
        if(board[y][i] == number) return false;
    }

    for(int j = 0; j<N ; j++){
        if(board[j][x] == number) return false;
    }

    int x_base = x/3; int y_base = y/3;
    x_base = x_base*3; y_base = y_base*3;
    for(int y = 0; y<3 ; y++){
        for(int x = 0; x<3 ; x++){
            if(board[y_base+y][x_base+x] == number) return false;
        }
    }

    return true;
}

bool solveSudoku(int board[9][9],int position){

    int x = position%9;
    int y = position/9;
   if(position == N*N) return true;
    if(board[y][x] != 0){
        if(solveSudoku(board,position+1)){
            return true;
        }
    }
    else{
        for(int i = 1; i<= 9; i++){
            if(isValid(i,board,position)){
                board[y][x] = i;
                if(solveSudoku(board,position+1)){
                    return true;
                }
                board[y][x] = 0;
            }
        }
    }
    return false;
}

void print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    // 0 means unassigned cells
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
 
    if (solveSudoku(grid, 0))
        print(grid);
    else
        cout << "no solution  exists " << endl;
 
    return 0;
}
