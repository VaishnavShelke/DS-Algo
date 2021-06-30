#include <iostream>
using namespace std;

// The painter’s partition problem

// 0 10 30 90 140 170 210

int partition(int n,int k,int* sumArr,int* memo){
    static int size = n;
    if(n == 1) return sumArr[0];
    if(k == 1) return sumArr[n];
    if(*(memo + size*k + n) != -1) return *(memo + size*k + n);
    int maxOfPartitions;
    int minOfAllCombinations = 99999;
    for(int i = 0; i<=n ; i++){
        maxOfPartitions = max(partition(i,k-1,sumArr,memo),sumArr[n] - sumArr[i]);
        minOfAllCombinations = min(minOfAllCombinations,maxOfPartitions);
    }
    *(memo + size*k + n) = minOfAllCombinations;
    return minOfAllCombinations;
}


int main()
{
    int arr[] = { 10, 20, 60, 50, 30, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int sumArr[n+1];
    sumArr[0] = 0;
    for(int i = 0; i<n ; i++) sumArr[i+1] = sumArr[i] + arr[i];
    int memo[n+1][k+1];
    for(int j = 0; j<=n ; j++){
        for(int i = 0; i<=k ; i++){
            memo[j][i] = -1;
        }
    }
    cout << partition(n, k,sumArr,&memo[0][0]) << endl;
 
    return 0;
}
