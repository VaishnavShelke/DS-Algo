#include <bits/stdc++.h>
using namespace std;

// QUICKSORT IMPLEMENTATION
// to find the kth largest element in a unsorted array

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

int partition_by(int arr[],int low,int high,int pivot){
    int piv = arr[pivot];
    int smaller_uptome = low - 1;
    for(int i = low; i <= high; i++){
        if (piv >= arr[i]){
            smaller_uptome++;
            swap(arr[i],arr[smaller_uptome]);
    }}
    return smaller_uptome;
    }

void print(int arr[],int sizearr){
    for(int i = 0;i<sizearr;i++){
        cout << arr[i] << " ";
        cout << "\n";
    }
}

int findkth(int arr[], int low,int high,int k){

    int result ;
    result = partition_by(arr,low,high,high);

    if (result == k){ return arr[k];}
    else if (result < k) {findkth(arr,result + 1,high,k);}
    else {findkth(arr,low,result-1,k);}

}



int main(){
    int arr[] = {3,22,5,7,4,6,7,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    int low = 0;
    int high = len-1;
    int kth = 7;
    cout << findkth(arr,low,high,kth-1);
    return 0;
}
