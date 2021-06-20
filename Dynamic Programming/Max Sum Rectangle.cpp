// Dynamic Programming Solution for Max Sum Rectangle
#include <limits.h>
#include<iostream>
#include<tuple>
# define ROW 4
# define COL 5
using namespace std;

tuple<int,int,int> kadanesFind(int* arr){

    int sum = arr[0];
    int left = 0,right = 0,up = 0,down = 0,maxSum = arr[0];
    for(int i = 1; i<ROW ; i++){
        if(arr[i] > arr[i] + sum){
            sum = arr[i]; left = i; right = i;
        }
        else{
            sum = arr[i]+sum;
            right = i;
        }
        if(sum > maxSum){
            up = left; down = right; maxSum = sum;
        }
    }

    return {up,down,maxSum};
}

void maxRectwithBaseL(int l,int& maxLeft,int&maxRight,int& maxUp,int& maxDown,int& maxSum,int M[ROW][COL]){

    int kadanesArr[ROW];
    int up,bottom,sum;
    tuple<int,int,int> upDownMax;
    for(int j = 0; j<ROW ; j++) kadanesArr[j] = 0;

    
    for(int r = l; r<COL ; r++){

        for(int j = 0; j<ROW ; j++) kadanesArr[j] += M[j][r];
        upDownMax = kadanesFind(kadanesArr);

        if(get<2>(upDownMax) > maxSum){
            maxSum = get<2>(upDownMax);
            maxLeft = l;
            maxRight = r;
            maxUp = get<0>(upDownMax);
            maxDown = get<1>(upDownMax);
        }

    }
}

void findMaxSum(int M[ROW][COL]){

    int maxLeft,maxRight,maxUp,maxDown,maxSum = INT_MIN;

    for(int L = 0; L<COL; L++){
        maxRectwithBaseL(L,maxLeft,maxRight,maxUp,maxDown,maxSum,M);
    }

    cout << "The max sum is ... "<<maxSum << endl << "From ... ";
    printf("( %d, %d) to ( %d, %d) ",maxLeft,maxUp,maxRight,maxDown);

    
}


// Driver Code
int main()
{
    int M[ROW][COL] = { { 1, 2, -1, -4, -20 },
                        { -8, -3, 4, 2, 1 },
                        { 3, 8, 10, 1, -3000 },
                        { -4, -1, 1, 7, 1000 } };
 
    // Function call
 
    findMaxSum(M);
    return 0;
}
