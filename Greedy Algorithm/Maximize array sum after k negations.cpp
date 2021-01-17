#include<bits/stdc++.h>
#include <iostream>
using namespace std;
 
// Maximize array sum after k negations

bool comparer(int a,int b){
    return(abs(a)>abs(b));
}
int main(){
    int arr[] = {-2, 0, 5, -1, 2};
    int len = sizeof(arr)/sizeof(arr[0]);
    int remaining_neg = 4;

    sort(arr,arr + len,comparer);
    int sum = 0;
    for(int i = 0;i<len && remaining_neg > 0;i++){
        if(arr[i]<0){
            remaining_neg--;
            sum += abs(arr[i]);
        }
        else{
            sum += arr[i];
        }
    }
    int correction;
    if (remaining_neg > 0){
            correction = -1*(remaining_neg%2)*arr[len-1];
            sum += correction;
    }
    cout << "The maximized array sum after given number of negations is ... " << sum;
}
