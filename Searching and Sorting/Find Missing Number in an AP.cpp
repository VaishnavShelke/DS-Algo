#include <iostream>
#include <bits\stdc++.h>

using namespace std;

/**
 * !            Find Missing Number in an Arithmetic Progression       
 **/

int main(){
    int arr[] = {-2, -4, -8, -10, -12, -14};
    int n = sizeof(arr)/sizeof(arr[0]);

    int factor;
    if(arr[n-1]>arr[0]) factor = 1;
    else factor = -1;

    int cd = factor*min(std::abs(arr[1]-arr[0]),std::abs(arr[n-1]-arr[n-2]));
    int first = arr[0];
    int reference;

    int high = n-1,low = 0,mid;

    while(high>low){
        mid = (high + low)/2;

        if(first + mid*cd == arr[mid]){
            low = mid+1; // Low before this manipulation represents the correct position
        }
        else{
            high = mid -1;
        }
    }
    cout << "The Missing Number is ... ";
    if(high != 0 & arr[high]-arr[high-1] != cd){
        cout << arr[high] - cd;
    }   
    if(high != n-1 & arr[high+1] - arr[high] != cd){
        cout << arr[high] + cd;
    }
}
