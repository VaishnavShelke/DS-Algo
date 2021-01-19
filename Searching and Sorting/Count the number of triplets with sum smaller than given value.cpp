#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Count the number of triplets with the sum less than the given value
/*
    Sorting is the key while doing count triplets/duplets/quadplate int such problems 
*/

void countduplates(int sum,int* arr,int low,int high,int *totaltrip);
int main(){
    int arr[] = {5, 1, 3, 4, 7}; // 1   3   4   5   7
    int len = sizeof(arr)/sizeof(arr[0]);
    int sum = 12,low,high;
    int totaltrip;
    totaltrip = 0;
    sort(arr,arr + len);
    int t_sum ;
    for(int i = 0;i<len-2;i++){
        t_sum = sum;
        t_sum -= arr[i];
        low = i+1; high = len-1;
        countduplates(t_sum,arr,low,high,&totaltrip);
    }
    cout << totaltrip;
}

void countduplates(int sum,int* arr,int low,int high,int* totaltrip){
    
    while(low <= high){
        if(arr[low] + arr[high] < sum){
            *totaltrip = *totaltrip + high - low;
            
            low++;
        }
        else{  // arr[low] + arr[high] >= sum
            high--;
        }
    }
}
