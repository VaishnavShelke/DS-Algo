#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

// Find if there exists any sub array in the array whose sum = 0
/*
Simple approach....
    Add all elements up to i {i == 0 -->> len - 1} in a different array
    find repeating elements in this sum array  
*/

bool find_if_repeat(int* A,int sizearr){
    map<int,int> counter;
    for(int i = 0; i<sizearr;i++){
        counter[A[i]]++;
        if (counter[A[i]] == 2)
            return true;
    }
    return false;
}
int main(){
    int arr[] = {4, 2, -3, 1, 6};
    int len = sizeof(arr)/sizeof(arr[0]);
    int sumarr[len+1];
    sumarr[0] = 0;

    for(int i = 1; i<len+1 ;i++){
        sumarr[i] = sumarr[i-1]+arr[i-1];
    }
    if(find_if_repeat(sumarr,len)){
        cout << "True ... Sum 0 sub array exists\n";
    }
    else{
        cout << "False ... Sum 0 sub array does not exists\n";
    }
    return 0;
}
