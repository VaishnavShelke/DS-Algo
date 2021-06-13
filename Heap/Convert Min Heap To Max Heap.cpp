#include <bits/stdc++.h>
using namespace std;

// Convert Min Heap To Max Heap in O(N) time


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyMe(int* arr,int heapSize){
    if(heapSize == 1) return;

    int child = heapSize-1;
    int parent = (child-1)/2;

    while(parent >= 0 && arr[parent] < arr[child]){
        swap(&arr[parent],&arr[child]);
        child = parent;
        parent = (child-1)/2;
    }
}

void convertMaxHeap(int* arr, int n){

    int heapSize;
    for(int i = 0 ; i<n/2 ; i++){
        heapSize = i+1;
        swap(&arr[i],&arr[n-1-i]);
        heapifyMe(arr,heapSize);
    }
    for(int i = n/2 ; i<n; i++){
        heapSize = i+1;
        heapifyMe(arr,heapSize);        
    }

    return;

}

void printArray(int *arr,int n){
    for(int i = 0 ; i<n ; i++){
        cout << arr[i] << " ";
    }
}

int main()
{
    // array representing Min Heap
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    printf("Min Heap array : ");
    printArray(arr, n);
 
    convertMaxHeap(arr, n);
 
    printf("\nMax Heap array : ");
    printArray(arr, n);
 
    return 0;
}
