#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// Count the number of inversions

// Count the number of inversions  ---->>>> To count the nuber of elements less than the given element to the right... for each element
                                            // Then add the result
/* 
    Merge Sort Technique:
            1. We divide the array into two parts;
                1. low -->> mid - 1 both inclusive
                2. mid -->> high    both inclusive
            2. The final number of inversions are...
                    inversions in low -->> mid-1 and mid -->> high
                    After the result of above recursive function is obtained then
                    Add...
                            The inversions obtained during merge process
            3. Calculating the number of inversions obtained during merge process
                    Suppose low -->> mid - 1 == 8,9  ptr -->> i = low
                            mid -->> high    == 7,6,5  ptr -->> j = high
                                            The elements are sorted due to merge action performed in earlier recursive function
            4.
                    There can be two possible situations 
                    A. element i < j;
                            Ok just do i++
                    B. element i > j;
                            total inversions += mid - i
                            
                            ************  
                                        Why mid - i ?????
                                        Because the number from the right array which is less than the ith element of the left array
                                        is also less than the elements from i -->> mid - 1....
*/

// log(n) merge sort modified technique

int count_inversions(int* A,int low,int high);
int mearge(int* A,int low,int high);
int main(){
    int arr[] = {2,7,6,5};
    int sizearr = sizeof(arr)/sizeof(arr[0]);
    int temp[sizearr];
    int high = sizearr - 1;
    int low = 0;
    int result = count_inversions(arr,low,high);
    cout << result;

}

int count_inversions(int* A,int low,int high){
    int mid = (low + high)/2;
    int result;

    if(high<=low) return 0;
    else if(low + 1 == high){
        if(A[low]>A[high]){
            swap(A[low],A[high]);
            return 1;
        }
        else return 0;
    }
    else
    result = count_inversions(A,mid,high) + count_inversions(A,low,mid-1) ;
    result +=  mearge(A,low,high);
    return result;
}


int mearge(int* arr,int low,int high){
    int mid = (low+high)/2;

    int k = low;
    int i = 0;
    int j = 0;
    int invcount = 0;
    int left[mid-low];
    int right[high-mid+1];

    for(int i = low; i<= mid-1; i++){
        left[i-low] = arr[i];
    }
    for(int i = mid; i<= high; i++){
        right[i-mid] = arr[i];
    }

    while(i< mid-low && j<high-mid+1){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
            k++;
        }
        else{
            arr[k] = right[j];
            j++;
            k++;
            invcount += mid - i - low;
            
        }
    }

    while(i< mid-low){
        arr[k] = left[i];
        i++;k++;
    }
    while(j< high-mid+1){
        arr[k] = right[j];
        j++;k++;
    }
    return invcount;
}
