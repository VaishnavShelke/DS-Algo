#include<iostream>
using namespace std;

// Find Kth largest element in two sorted arrays

int kthelementUtil(int* arr1,int* arr2,int* end1,int* end2,int kth){

/*
            int arr1[5] = {2, 9, 12, 30, 40};
            int arr2[4] = {1, 4, 8, 10};
*/
    if(arr1 == end1) return arr2[kth];
    if(arr2 == end2) return arr1[kth];
    int mid1 = (end1-arr1)/2; // 2
    int mid2 = (end2-arr2)/2; // 2 

    if(mid1 + mid2 < kth){
        if(arr1[mid1]>arr2[mid2]){
            return kthelementUtil(arr1,arr2+mid2+1,end1,end2,kth-mid2-1);
        }
        else{ // arr1[mid1] < arr2[mid2]
            return kthelementUtil(arr1+mid1+1,arr2,end1,end2,kth-mid1-1);
        }
    }
    else{
        if(arr1[mid1]>arr2[mid2]){
            return kthelementUtil(arr1,arr2,arr1 + mid1,end2,kth);
        }
        else{ // arr1[mid1] < arr2[mid2]
            return kthelementUtil(arr1,arr2,end1,arr2 + mid2,kth);
        }

    }



}



int kthelement(int* arr1,int* arr2,int n1,int n2,int kth){

    return kthelementUtil(arr1,arr2,arr1+n1,arr2+n2,kth);

}

// Driver Code
int main()
{
    int arr1[5] = {2, 9, 12, 30, 40};
    int arr2[4] = {1, 4, 8, 10};
    int k = 8;
    cout << kthelement(arr1, arr2, 5, 4, k-1);
    return 0;
}
