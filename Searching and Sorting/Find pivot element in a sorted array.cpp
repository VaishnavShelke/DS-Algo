#include <iostream>
#include <bits\stdc++.h>

using namespace std;

// Find pivot element in the sorted array

int main(){
    int arr[] = {5,7,9,10,34,56,76,87,2,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    int low = 0; int high = len - 1;
    int mid = (low+high)/2;
    while(high > low){
        if(arr[low]>arr[high]){
            mid = (low+high)/2;
            if(arr[mid] > arr[low]){
                high = high;
                low = mid;
            }
            else{
                high = mid;
                low = low;
            }
        }
        if(low + 1 == high){
            break;
        }
    }
    cout << "The pivot is ... " << min(arr[low],arr[mid]);
    return 0;
}
