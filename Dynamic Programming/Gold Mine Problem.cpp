#include <iostream>
#include <vector>
using namespace std;

// Gold Mine Problem

/*
  You can move to the right/diagonally-upward right or diagonally-downward right from the leftmost column to
  the rightmost column
  Now you assume that you have reached your destination i.e the rightmost column, you cannot move anywhere from here
  
  Now you can reach at the leftmost tile,from any three previous tiles
  Which one do you take ....????
  
        The answer is the tile at the back for which { You will need to traverse max value gold mines }
        And what will be your new/current collection -->> collection_max upto previous decided tile + value at current tile
*/
/* Hence by optimal subproblem you got the max collection possible to reach the rightmost column for each tile/row individually
   Now out of the collection of last column choose the max one then thats you answer.....
*/



int main(){
    int n_rows = 4,m_cols = 4;
    int mat[n_rows][m_cols] = {{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};
    int collection[n_rows][m_cols];
    int dummy;
    for (int col = 0; col < m_cols; col++){
        for (int row = 0;row < n_rows; row++){
            if (col == 0) {collection[row][col] = mat[row][col]; continue;}
            if (row == 0) {collection[row][col] = max(collection[row+1][col-1],collection[row][col-1]) + mat[row][col];continue;}
            else if(row == n_rows - 1) {collection[row][col] = max(collection[row-1][col-1],collection[row][col-1]) + mat[row][col];continue;}
            else {
                dummy = max(collection[row-1][col-1],collection[row][col-1]);
                collection[row][col] = max(dummy,collection[row+1][col-1]) + mat[row][col];
            }
        }
    }

    int answer = 0;
    for(int j; j < n_rows; j++){
        answer = max(answer,collection[j][m_cols-1]);
    }
    cout << "The largest collection possible with given gold matrix is  "<< answer;
    return 0;
}
