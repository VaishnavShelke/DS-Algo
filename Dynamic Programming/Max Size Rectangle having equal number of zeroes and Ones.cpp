#include <iostream>
#include <unordered_map>
using namespace std;
#define INFMIN -99999
#define ROW 4
#define COL 4

pair<int,int> sub_array_with_sum0(int* sumArr){
    unordered_map<int,int> firstOccurIndex;
    int sumofArr[ROW+1]; sumofArr[0] = 0;
    int up = INFMIN,down = INFMIN;
    for(int i = 0; i<ROW; i++){
        sumofArr[i+1] = sumofArr[i] + sumArr[i];
    }

    int maxDiff = INFMIN;

    for(int i = 0; i<= ROW; i++){
        if(firstOccurIndex.find(sumofArr[i]) == firstOccurIndex.end()){
            firstOccurIndex[sumofArr[i]] = i;
        }
        else{
            if(maxDiff < i - sumofArr[i]){
                up = sumofArr[i];
                down = i-1;
                maxDiff = i - sumofArr[i];
            }
        }
    }

    return {up,down};

}

void maxReservationRectanglebaseL(int l,int mat[ROW][COL],int& maxLeft,int& maxRight,int& maxUp,int& maxBottom,int& maxSize){

    int sumArr[ROW];
    pair<int,int> upBottom;
    for(int i = 0; i<ROW ; i++) { sumArr[i] = 0;}
    for(int r = l ; r<COL ; r++){
        for(int i = 0; i<ROW ; i++) {
            if(mat[i][r] == 0) sumArr[i] -= 1;
            else sumArr[i] += 1;
        }

        upBottom = sub_array_with_sum0(sumArr);
        cout << upBottom.first << " " << upBottom.second << endl;

        if(upBottom.second != INFMIN && upBottom.first != INFMIN && (upBottom.second-upBottom.first+1)*(r-l+1)>maxSize){
            maxSize = (upBottom.second-upBottom.first+1)*(r-l+1);
            maxLeft = l;
            maxRight = r;
            maxUp = upBottom.first;
            maxBottom = upBottom.second;
        }
        
    }
}

void maxReservationRectangle(int mat[ROW][COL],int row,int col){

    int maxRight, maxLeft,maxUp, maxBottom, maxSize;

    for(int l = 0; l<COL ; l++){
        maxReservationRectanglebaseL(l,mat,maxLeft,maxRight,maxUp,maxBottom,maxSize);
    }

    cout << "The largest subMatrix with equal number of Zeroes and Ones is :  ";
    printf( "( %d, %d) ---> ( %d, %d) ",maxUp,maxLeft,maxBottom,maxRight);


}
// Driver program to test above
int main()
{
    int mat[ROW][COL] = { {0, 0, 1, 1},
                        {0, 1, 1, 0},
                        {1, 1, 1, 0},
                        {1, 0, 0, 1} };    

    int row = 4, col = 4;
    maxReservationRectangle(mat, row, col);
    return 0;                      
                        
} 
