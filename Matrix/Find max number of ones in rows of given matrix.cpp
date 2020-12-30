#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

const int N = 30;


// Count the maximum number of ones in the rows of the given matrix
        // USING UPPER_BOUND AND LOWER _BOUND

// If M + i --->>> pointer of ith array
// ... Then *(M + i) --->>> ith array / pointer of first element of ith array

int findtotones(bool A[],int width){

    int no_of_ones = upper_bound(A,A+width,1) - lower_bound(A,A+width,1);
    cout << "\nUpper Bound ... "<< upper_bound(A,A+width,1)  - A<<"  Lower Bound ... "<< lower_bound(A,A+width,1) -A;
    return no_of_ones;
}

int main(){
    bool matrix[][N] = {{0,0,0,0,1,1},
                        {0,0,1,1,1,1},
                        {0,0,1,1,1,1}};
    int width = 6 ;
    int height = 3 ;
    int maxima = INT_MIN;
    int temp;
    for(int i = 0; i< height; i++){
        temp = findtotones(matrix[i],width);
        maxima = max(maxima,temp);
    }
    cout << "\nThe maximum number of ones int the row of the array is... "<< maxima;
    return 0;
}
