#include<bits/stdc++.h>
#include <iostream>
using namespace std;
 
// Maximum Product Subset of an array

bool comparer(int a,int b){
    return(abs(a)>abs(b));
}
int main(){
    int arr[] = { -6, 4, -5, 8, -10, 0, 8 };
    int len = sizeof(arr)/sizeof(arr[0]);

    // Sort by absolute values
    sort(arr,arr+len,comparer);
    int lastneg = 1;
    int maxprod = 1;
    for(int i = 0;i<len ; i++){
        if(abs(maxprod) < abs(maxprod*arr[i])){
            maxprod  = maxprod*arr[i];
            if(arr[i]<0) lastneg = arr[i];
        }
        else
        {break;}
     }
    if(maxprod < 0) maxprod = maxprod/lastneg;

    cout << "The maximum product of any possible subset array is ... Any guesses ... "<< maxprod;
    return 0;
}
