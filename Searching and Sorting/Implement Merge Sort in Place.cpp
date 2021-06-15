#include <bits/stdc++.h>
using namespace std;



// Implement Merge Sort in Place

void swap(int* a1,int* a2){
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

void mergeArray(int* arr,int s1,int e1,int s2,int e2){

    int index = s1;
    int ptr2 = s2;
    int inst;

    while(ptr2<=e2 && index<=e2){
        if(arr[index]<arr[ptr2]){
            index++;
        }
        else{
            inst = ptr2;
            while(inst > index ){
                swap(&arr[inst],&arr[inst-1]);
                inst--;
            }
            ptr2++;
            index++;
        }

    }

}


void mergeSort(int* arr,int low,int high){

    if(high <= low) return;
    int mid = (low + high)/2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);

    mergeArray(arr,low,mid,mid+1,high);
}

int main(){
    int arr[] = {10,9,8,7,6,5,4,3,2,1,-1};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i = 0; i<n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
