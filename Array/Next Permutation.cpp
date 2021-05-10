#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;

// Next permutation

int main(){
    int arr[] = {2,3,7,2,6,4,7,4,3,7};
    int length = sizeof(arr)/sizeof(arr[0]),i;

    cout << "Original Number ...\n";
    for(int j = 0; j<length ; j++) cout<< arr[j] << " ";

    for(i = length-1; i>=0; i--){
        if(arr[i] < arr[length-1]){
        swap(arr[length-1],arr[i]); break;
    }}

    sort(arr + i+1,arr + length);
    
    cout << "\nNext Permutation ...\n";
    for(int j = 0; j<length ; j++) cout<< arr[j] << " ";
    return 0 ;
}
