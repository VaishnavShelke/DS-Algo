#include <iostream>
#include <bits\stdc++.h>
using namespace std;


/**
 * !                     Chocolate Distribution Problem                               
 * *                                               
 **/

int main(){
    int arr[] = { 12, 4,  7,  9,  2,  23, 25, 41, 30,
                  40, 28, 42, 30, 44, 48, 43, 50 };
    int m = 7; // Number of students
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr,arr+n);

    int minDiff = INT_MAX;
    int maxChoc = m-1;
    while(maxChoc<n){
        minDiff = min(minDiff,arr[maxChoc]-arr[maxChoc-m+1]);
        maxChoc++;
    }    

    cout << "Minimum difference is " << minDiff;
}
