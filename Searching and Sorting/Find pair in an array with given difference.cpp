#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// Find a pair in the array with the given difference

int main(){
    int arr[] = {5, 20, 3, 2, 50, 80};
    int len = sizeof(arr)/sizeof(arr[0]);
    int diff = 78;

    for(int i = 0; i<len; i++){
        for(int j = i+1; j<len; j++){
                if(abs(arr[i] - arr[j]) == diff){
                    printf("The apir with the given difference is ( %d, %d )",i,j);
                    return 0;
                }
        }
    }  
    cout << "No such pair exists ...";
    return 0;
}
