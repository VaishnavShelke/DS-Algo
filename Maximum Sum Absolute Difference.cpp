#include <iostream>
#include <bits\stdc++.h>

using namespace std;

// Maximum sum of absolute difference of any premutation of a given array
/*
    My space optimized version
*/

int main(){
    int arr[] = { 11,34,5,56, 2, 4, 5,7,8,9,2,23,32,544,65,57,8 };;
    int len = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+len);
    int low = 0;int high = len-1;
    int sum = 0;
    
    while(high > low){
        sum += arr[high]-arr[low];
        sum += arr[high]-arr[low+1];
        high--;
        low++;
    }
    sum += arr[low] - arr[0];

    cout<< "The maximum absolute difference sum of the array is ... " << sum;
    return 0;
}
