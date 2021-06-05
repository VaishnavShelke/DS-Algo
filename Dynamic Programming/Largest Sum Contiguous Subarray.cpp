#include <iostream>
#include <bits\stdc++.h>
using namespace std;


/**
 * !                LARGEST SUM CONTIGIOUS SUBARRAY                 
 **/

int main(){
    int arr[]  = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxSum;
    int largestSumUpto[n];
    maxSum = largestSumUpto[0] = arr[0];
    for(int i = 1; i<n ; i++){
        if(largestSumUpto[i-1] + arr[i] > arr[i]){
            largestSumUpto[i] = largestSumUpto[i-1] + arr[i];
        }
        else{
            largestSumUpto[i] = arr[i];
        }
      if(largestSumUpto[i]<0)
         largestSumUpto[i] = 0;
        maxSum = std::max(maxSum,largestSumUpto[i]);

    }
    cout << "The maximum sun of the contigous subarray is ... ";
    cout << maxSum;
    return 0;
    
}
