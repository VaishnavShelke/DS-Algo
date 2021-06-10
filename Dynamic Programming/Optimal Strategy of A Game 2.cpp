#include <iostream>
#include <bits\stdc++.h>
using namespace std;
#define N 9

// THE GAME OF EQUALLY SMARTS.....
// APPROACH 2

int iPlay(int low,int high,int* arr,int sum){
    if(low>high) return 0;
    int selectLow = arr[low] + (sum-arr[low] - iPlay(low+1,high,arr,sum-arr[low]));
    int selectHigh = arr[high] + (sum-arr[high] - iPlay(low,high-1,arr,sum - arr[high]));
    int myScore = max(selectHigh,selectLow);

    return myScore;
}

int optimalStrategyOfGame(int* arr, int n){
    int sum = 0;
    for(int i = 0; i<n; i++) sum += arr[i]; 
    return iPlay(0,n-1,arr,sum);
}
int main()
{
    int arr1[] = { 8, 15, 3, 7 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n",
           optimalStrategyOfGame(arr1, n));
 
    int arr2[] = { 2, 2, 2, 2 };
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n",
           optimalStrategyOfGame(arr2, n));
 
    int arr3[] = { 20, 30, 2, 2, 2, 10 };
    n = sizeof(arr3) / sizeof(arr3[0]);
    printf("%d\n",
           optimalStrategyOfGame(arr3, n));
 
    return 0;
}
