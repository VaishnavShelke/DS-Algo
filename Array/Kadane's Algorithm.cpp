#include <iostream>
#include <typeinfo>
using namespace std;

// Kadane's Algorithm

// Max Contigous Subarray sum 
//            TimeComplexity -->> O(n)
//            SpaceComplexity -->> O(1)                                

int main(){
    int arr[] = {1,2,3,-2,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    int maxima;
    int temp_prev = arr[0];
    maxima = temp_prev;
    for(int i = 1;i < len; i++){
        temp_prev = max(temp_prev + arr[i],arr[i]);
        maxima = max(temp_prev,maxima);
    }
    cout <<"Maximum sum subarray is \n ........  ";
    cout << maxima;
    return 0;
}
