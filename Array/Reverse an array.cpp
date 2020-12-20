#include <iostream>
#include <vector>
using namespace std;

// Reverse The array using swapping

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int length = sizeof(arr)/sizeof(arr[0]);
    for(int i =0; i< length/2 ; i++) swap(arr[i],arr[length-i-1]);

    for(int i = 0;i<length; i++) cout << " " << arr[i] ;
    return 0;

}
