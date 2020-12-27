#include <bits/stdc++.h>
using namespace std;

// Find kth largest element;
// Heap/Quicksort

/* First of all let us understand how do we partition the array on the basis of pivot
        so we take the last element of the given piece of array and assign its value to variable pivot
        
        We begin with initializing a pointer{not actual pointer}
        which stores the position, the peculiarity of this position is such that the element to the
        right of this position are compulsorily lesser than the pivot and at that position greater... 
        
        So we assign the vale to this pointer as low.
        Now we run a loop from beginning low -->> high by i.
        
            1. As i points to the the location with value greater than pivot we do nothing;
            2. As i points to the location having value lesser than the pivot what we do is we replace this {i} value with 
            the value at pointer. 
            so what happens is that the values in array UPTO and AT pointer are <<== pivot,
            Now increase the pointer by 1 ,hence the previously described property of the pointer is retained
        
*/
/* First let us understand mechanism of quicksort
    In quicksort we partition the array into two halves at one side all elements lesser than or equal to
    the pivot and at other side the elements greater than the pivot.
    
    NOW you see this first pivot we make and position it according to the given law of array bifurcation.
    The position it occupies wrt array is its fixed position and it will not move anywhere in future.
    
    SO THIS IS OUR KTH LARGEST // SMALLEST ELEMENT...............
    
    Now we know that we will have to run this process till our kth positionis occupied by pivot for this
    1. If pivot_occupied_position > k
            run partioning algo from low to pivot_occupied_position -1;
    2. If pivotz_occupied_position < k;
            run partioning algorithm from pivot_occupied_postion + 1 to high;
    3. YOU MADE IT MANNNNNNNNN.......
*/
int partitionby(int* A,int low,int high){
    int pivot = A[high];
    int smalluptome = low;            // It is certian that the elements to the left are compulsorily smaller than pivot.
                                      // Not sure about the element it is standing on........
    for(int i = low;i <= high;i++){
        if(A[i] <= pivot){
            swap(A[i],A[smalluptome]);
            smalluptome++;
        }
    }
    return smalluptome-1;
}

int kthlargest(int* arr,int low,int high,int k){
    int result = partitionby(arr,low,high); // returns the final position of the pivot

    if (result == k){return *(arr+k);}
    else if (result < k) {return kthlargest(arr,result+1,high,k);}
    else {return kthlargest(arr,low,result-1,k);}
}


int main(){
    int arr[] = {1,6,4,3,7,7,6,9};
    int k = 8;
    int len = sizeof(arr)/sizeof(arr[0]);
    int low = 0;
    int high = len - 1;
    cout << kthlargest(&arr[0],low,high,k-1);
}

