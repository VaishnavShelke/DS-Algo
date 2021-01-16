#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Find the repeating and the missing
/*
    XOR Method
*/

int main(){
    int arr[] = {1,2,3,4,5,6,9,9,7,8}; // 1,2,3,4,5,6,7,8,9,10
    int len = sizeof(arr)/sizeof(arr[0]);
    // Find the diffrentiating bit in "the missing" and "the repeating"
    int xorproduct = 0;
    for(int i = 0; i<len ; i++){
        xorproduct = xorproduct^arr[i]^(i+1);
    }

    // the first differenciating bit
    int first = 0;
    while(xorproduct>>first & 1 != 1){
        first++;
    }

    //now segregrate on the basis of the first bit

    int remaining = 0;
    int repeating = 0;

    for(int i = 0; i<len ;i++){
            if((i+1)>>first & 1 == 1){
                remaining = remaining^(i+1);
            }
            else{
                repeating = repeating^(i+1);
            }
            
            if(arr[i] >> first & 1 == 1){
                remaining = remaining^arr[i];
            }
            else{
                repeating = repeating^arr[i];
            }
    }
    cout << "The remaining-repeating or repeating-remaining elements are ..... " << remaining << " " << repeating ;
    return 0;
}
