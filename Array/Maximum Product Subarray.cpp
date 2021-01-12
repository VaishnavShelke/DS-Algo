#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Maximum Product Subarray
// Dynamic Programming Memory-Efficient

int main(){
    int arr[] = {2, 3, 4, 5, -1, 0};
    int arrlen = sizeof(arr)/sizeof(arr[0]);
    int prevhighest = 0;
    int maximumprod = 0;

    for(int i = 0;i<arrlen;i++){
        prevhighest = max(abs(prevhighest*arr[i]),abs(arr[i]));
        maximumprod = max(prevhighest,maximumprod);
    }
    cout << "The product of maximum product subarray is .... " << maximumprod;
    return 0;
}
