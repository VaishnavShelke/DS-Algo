#include <iostream>
#include <bits\stdc++.h>
using namespace std;


/**
 * !                            Smallest Sum Contigious Subarray                               
 * *                                    Space Optimized                
 * *                 
 **/

int main(){
    int arr[] = {3, -4, 2, -7, -1, 7, -5,-10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int first;
    int smallestSum;
    int small = smallestSum = std::min(0,arr[0]);

    for(int i = 1; i<n ; i++){
        if(smallestSum + arr[i] < arr[i]){
            smallestSum  = smallestSum + arr[i];
        }
        else{
            smallestSum = arr[i];
        }
        if(smallestSum > 0) smallestSum = 0;
        small = min(small,smallestSum);
    }

    cout << "The smallest sum of contigious subarray is ... " << small;

    return 0;
}
