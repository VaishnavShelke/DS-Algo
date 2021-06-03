#include <iostream>
#include <bits\stdc++.h>
using namespace std;

#define n 4

/**
 * !      Mearge K sorted Arrays using Recursive Divide and conquer         
 **/
int* mergeKArrays(int arr[][n],int low,int high){

    if(low == high) return arr[low];

    int mid = (low + high)/2;
    int* arr1 = mergeKArrays(arr,low,mid);
    int* arr2 = mergeKArrays(arr,mid+1,high);

    int size1 = 4*(mid-low+1);
    int size2 = 4*(high-(mid+1)+1);

    int* temp = new int[size1 + size2];

    int ptr1=0,ptr2=0;
    for(int i = 0 ; i<size1 + size2; i++){
        if(ptr1<size1 && ptr2<size2){
            if(arr1[ptr1]<arr2[ptr2]){
                temp[i] = arr1[ptr1]; ptr1++;
            }
            else{
                temp[i] = arr2[ptr2]; ptr2++;
            }
        }
        else if(ptr1<size1){
            temp[i] = arr1[ptr1]; ptr1++;
        }
        else{
            temp[i] = arr2[ptr2]; ptr2++;
        }
    }
    return temp;
}

void printArray(int* output,int total){
    for(int i = 0; i<total; i++){
        cout << output[i] << " ";
    }
    return;
}

int main()
{
    // Change n at the top to change number of elements
    // in an array
    int arr[][n] =  {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}};
    int k = sizeof(arr)/sizeof(arr[0]);
 
    int *output = mergeKArrays(arr, 0,k-1);
    
    cout << "Merged array is " << endl;
    printArray(output, n*k);
 
    return 0;
}
