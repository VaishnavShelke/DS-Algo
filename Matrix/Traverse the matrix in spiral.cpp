#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// SPIRAL TRAVERSE THE 2D MATRIX

/*
In this solution we run four loops for the motion in four directions reducing
the size of rectangle by 2 units in each direction PER cycle FROM BOTH sides
*/

int main(){
    int matrix[][5] = {{ 1, 2, 3, 4, 5},
                      {14,15,16,17, 6},
                      {13,20,19,18, 7},
                      {12,11,10, 9, 8}};
    int width = sizeof(matrix[0])/sizeof(matrix[0][0]);
    int height = sizeof(matrix)/sizeof(matrix[0]);
    int sh = 0,sw = 0;

    while(sh<height && sw<width){

        for(int i = sw;i < width;i++){
            cout << matrix[sh][i] << " ";
        }
        sh++;
        for(int i = sh;i < height;i++){
            cout << matrix[i][width-1] << " ";
        }
        width--;
        for(int i = width-1; i>= sw;i--){
            cout << matrix[height-1][i] << " ";
        }
        height--;
        for(int i = height-1; i>= sh; i--){
            cout << matrix[i][sw] << " ";
        }
        sw++;
    }
    return 0;
}
