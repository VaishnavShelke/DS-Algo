#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
using namespace std;

// Right Shifting an array by 1
// Arrays are immutable in C++
void rightshift_by1(int arr[],int sizearr);
int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int len = sizeof(arr)/sizeof(arr[0]);
    rightshift_by1(arr,len);                         // Whenever an array is passed in a function in C++
                                                     // It is the pointer that is passed by default.
                                                     // Thats why always pass the size of the array alongside
    for(int i = 0; i<len ; i++){
        cout << arr[i] << " ";
    }
}

void rightshift_by1(int brr[],int sizearr){
    int x = brr[sizearr-1];
    for(int i = sizearr - 1; i > 0;i--){
        brr[i] = brr[i-1];
    }
    brr[0] = x;
}
