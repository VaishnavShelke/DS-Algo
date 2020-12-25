// Implementing a heap sort with the use of oop object

#include <iostream>
#include <vector>
using namespace std;
#include<map>
#include<algorithm>
#include<typeinfo>


// Lets rather than making a function to heap sort the given input array

class HeapSort{
public:
    int *heap;
    int heapsize;
    HeapSort(int arr[],int arrsize,bool asc);
    void construct_heap();
    void heapify(int i);
    int rightchild(int i) {return (2*i + 2);}
    int leftchild(int i) {return (2*i + 1);}
    int extract_min();
    void heapsort();
};

HeapSort :: HeapSort(int arr[],int arrsize,bool asc){
    if ( asc == true){
        for(int i = 0;i < arrsize; i++) arr[i] = -1*arr[i];
    }
    heap = arr;
    heapsize = arrsize;
    int i = (heapsize-1)/2;
    construct_heap();
    heapsort();
    if ( asc == true){
        for(int i = 0;i < arrsize; i++) arr[i] = -1*arr[i];
    }
}

void HeapSort :: construct_heap(){
    int i = (heapsize-1)/2;
    while (i >= 0){
        heapify(i);
        i--;
    }
}

void HeapSort :: heapify(int i){
    int par = i;
    int rc = rightchild(i);
    int lc = leftchild(i);
    int smallest = par;

    if (lc < heapsize && heap[lc] < heap[par])
        smallest = lc;
    if (rc < heapsize && heap[rc] < heap[smallest])
        smallest = rc;
    if (smallest != par) { swap(heap[smallest],heap[par]); heapify(smallest);}
}

void HeapSort :: heapsort(){
    int t_size = heapsize;
    for (int i = 0; i<t_size ; i++){
        heap[t_size-1-i] = extract_min();
    }
}

int HeapSort :: extract_min(){
    int result = heap[0];
    heap[0] = heap[heapsize-1];
    heapsize --;
    heapify(0);
    return result;
}

int main(){
    int arr[] = {22,33,21,3,54,6,56,76,76,4,5,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    HeapSort sorter(arr,len,true);
    for(int i = 0; i<len ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
