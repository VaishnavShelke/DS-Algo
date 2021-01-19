#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// A product array puzzle
/*
    Don't use division anywhere at any place.
    For every index calculate product of all elements in array excluding arr[i]

    Approach:
        Use two arrays 
        one stores the value of multiplication of all elements BEFORE i;
        other stores the value of multiplication of all elements AFTER i;
*/

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr)/sizeof(arr[0]);
    int ltor[len+1]; int rtol[len+1];         // Short terms for Left to Right and Roght to Left respectively
    ltor[0] = 1; rtol[len] = 1;
    int temp1 = 1,temp2 = 1; 
    for(int i = 0; i<len ; i++){
        temp1 = temp1*arr[i];
        ltor[i+1] = temp1;

        temp2 = temp2*arr[len-1-i];
        rtol[len-i-1] = temp2;
    }

    // ltor = {1 ,1 , 2, 6, 24, 120}
    // rtol = {120, 120, 60, 20, 5, 1}

    for(int i = 0; i<len ; i++){
        cout << "For index " << i <<  " " << ltor[i]*rtol[i+1] << "\n";
    }
    return 0;
}
