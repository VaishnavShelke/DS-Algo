#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// Arrange elements in alternative positive and negative order
/*
 Check at even index if element is negative
    1. Yes then continue
    2. No then
            let the current index be i
            traverse the array from i to the index where the element is negative
            *** note that the index hence obtained should carry the first negative after i
                    {first negative}
            Now simply right shift the sub array from i-->>first negative {both inclusive}
    Vice versa for odd positions
    
    Note: If the array length is traversed but still the first positive-negative are not found terminated the operation
        print the array in its current state;
*/
            

void rightshiftfrom(int first,int last,int* A){
    int temp = A[last];
    for(int i = last; i>first;i--){
        A[i] = A[i-1];
    }
    A[first] = temp;
}


int main(){
    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int len = sizeof(arr)/sizeof(arr[0]);
    int firstpos,firstneg;
    int i,j;
    for(i = 0;i <len;i++){
        if(i%2 == 0){
            if(arr[i]>=0){
                for( j = i;j<len;j++){
                    if(arr[j]<0){
                        break;
                    }
                }
            if (j==len) break;
            firstneg = j;
            rightshiftfrom(i,firstneg,arr);
            }
        }
        else{
            if(arr[i]<0){
                for(j = i; j<len;j++){
                    if(arr[j]>=0){
                        break;
                    }
                }
            if(j == len) break;
            firstpos = j;
            rightshiftfrom(i,firstpos,arr);
            }
        }
    }

    for(i = 0; i<len; i++) cout<< arr[i] << " ";
    return 0;

}
