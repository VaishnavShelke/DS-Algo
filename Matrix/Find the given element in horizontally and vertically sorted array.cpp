#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// Find a number in the 2D array sorted vertically and horizontally

pair<int,int> findme(int* M,int height,int width,int col,int number);
int main(){
    int N = 4;
    int number = 29;
    int matrix[][N] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
    int height = sizeof(matrix)/sizeof(matrix[0]);
    int width = sizeof(matrix[0])/sizeof(matrix[0][0]);
    pair<int,int> result;
    // Find tentative array in which it may lie
    // i.e find the k for which
    // matrix[k][0] <= number < matrix[k+1][0]


    for(int i = width-1;i>=0; i--){
        if (matrix[0][i] == number){
            printf("Found At... ( %d, %d)\n",0,i);
            return 0;
        }
        else if(matrix[0][i] > number){
            continue;
        }
        else{
            result = findme(&matrix[0][0],height,width,i,number);
            if(result.second == INT_MAX){
                break;
            }
            else{
                printf("Found At... ( %d, %d)\n",result.first,result.second);
                return 0;
            }
        }
    }
    cout << "Could not find your element..... :(";
    return 0;

}

pair<int,int> findme(int* M,int height,int width,int col,int number){


    int high = height - 1,low = 0;

    while(high>low){
        int mid = (high + low)/2;
        if(*(M + mid*width + col) == number){
            return make_pair(mid,col);
        }
        else if(*(M + mid*width + col) > number){
            high = mid - 1;
            low = low;
        }
        else{
            low = mid + 1;
            high = high;
        }
    }
    return make_pair(INT_MAX,INT_MAX);

}
