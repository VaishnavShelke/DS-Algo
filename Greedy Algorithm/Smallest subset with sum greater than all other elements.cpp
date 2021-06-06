#include <iostream>
#include <bits\stdc++.h>
using namespace std;


/**
 * !                      Smallest subset with sum greater than all other elements                               
 * *                                               
 **/

bool comparer(int n1, int n2){
    return n1>n2;
}
int main(){

    int arr[] = {3, 1, 7,4,3,6,7,8,1,2,3,4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;


    for(int i = 0; i<n ; i++){
        sum += arr[i];
    }
    sum = ceil(sum/2);

    sort(arr,arr+n,comparer);

    int newSum = 0;int i = 0;
    while(newSum < sum){
        newSum += *(arr + i);
        i++;
    }
    cout << "The smallest subset with greater sum ... ";
    for(int j = 0; j<i ; j++){
        cout << arr[j] << " ";
    }
    return 0;
}

