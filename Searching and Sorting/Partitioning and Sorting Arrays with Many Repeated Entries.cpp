
#include<iostream>
using namespace std;

// The Dutch Partition Problem

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

pair<int,int> threeWayPartition(int* arr,int low,int high){

    // { 3, 3, 3, 1, 4, 4, 4, 4, 4, 4, 9, 5, 4 }
    int pivot;
    int mid1 = low-1;
    int mid2 = low-1;
    pivot = arr[high]; 
    // 9 9 5 9
    for(int i = low; i<high ; i++){
        if(arr[i]<pivot){
            mid1++; mid2++;
            swap(&arr[i],&arr[mid2]);
            swap(&arr[mid1],&arr[mid2]);
        }
        else if(arr[i] == pivot){
            mid2++;
            swap(&arr[i],&arr[mid2]);
        }
    }
    mid2++;
    swap(&arr[high],&arr[mid2]);
    return {mid1,mid2+1};
}

void quickSort(int* arr,int low, int high){
    if(low >= high) return ;
    pair<int,int> mid1_mid2 = threeWayPartition(arr,low,high);
    quickSort(arr,low,mid1_mid2.first);
    quickSort(arr,mid1_mid2.second,high);

}

void printarr(int* arr,int size){
    for(int i = 0; i<size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = { 4, 9, 4, 4, 1, 9, 4, 3, 3, 3, 1, 4, 4, 4, 4, 4, 4, 9, 4, 1, 9, 4, 3, 3, 3, 1, 4, 4, 4, 4, 4, 4, 9, 5, 4 };
    int size = sizeof(a) / sizeof(int);
   
      // Function Call
    printarr(a, size);
    quickSort(a,0,size-1);
    printarr(a, size);
    return 0;
}
