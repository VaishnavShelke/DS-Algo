#include<bits/stdc++.h>
#include <iostream>
using namespace std;
 
// Maximize the sum of arr[i]*i


int main(){
    int arr[] = {-2, 0, 5, -1, 2};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    sort(arr,arr+len);
    int sum = 0;
    for(int i = 0;i<len;i++){
            sum += arr[i]*i;
    }
    cout << "The maximized sum is ... " << sum;
    return 0;
}
