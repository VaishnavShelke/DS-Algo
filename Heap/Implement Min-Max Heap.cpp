#include <iostream>
#include <vector>
using namespace std;
#include<map>
#include<algorithm>
#include<typeinfo>

/* Please Notice how using the concept of inheritance 
   did i implement max heap with just minimal addition to the methods of
   the MinHeap */
class MinHeap{
public:
    int heapsize = 0;
    vector<int> heap;
    //MinHeap();
    void aad_element(int ele);
    void bottomup_heapify(int i);
    int minimum();
    void heapify(int i);
    int extract_min();
    int leftchild(int i) { return 2*i + 1;}
    int parent(int i) { return (i-1)/2;}
    int rightchild(int i) { return 2*i + 2;}
};


void MinHeap :: aad_element(int ele){
    heap.push_back(ele);
    heapsize ++;
    if (heapsize > 1)
    bottomup_heapify(heapsize-1);
}

void MinHeap :: bottomup_heapify(int i){
    int par = parent(i);
    int self = i;

    while(heap[par]> heap[self]){
        if (self == 0) break;
        swap(heap[par],heap[self]);
        self = par;
        par = parent(par);
    }
}

int MinHeap :: minimum(){
    if (heapsize == 0) return INT_MAX;
    else return heap[0];
}

int MinHeap :: extract_min(){
    if (heapsize == 0) return INT_MAX;

    int result = heap[0];
    heap[0] = heap[heapsize-1];
    heapsize--;
    heapify(0);
    return result;
}

void MinHeap :: heapify(int i){
    int par = i;
    int lc = leftchild(i);
    int rc = rightchild(i);
    int smallest = par;

    if(lc < heapsize && heap[lc] < heap[par]){
        smallest = lc;
    }
    if(rc < heapsize && heap[rc] < heap[smallest]){
        smallest = rc;
    }
    if (smallest != par) { swap(heap[par],heap[smallest]); heapify(smallest);}

}

////// IMPLEMENTED MIN HEAP

class MaxHeap : public MinHeap{
public:
    void aad_element_max(int ele);
    int extract_max();
    int maximum();
};

void MaxHeap :: aad_element_max(int ele){
    ele = -1*ele;
    aad_element(ele);
}
int MaxHeap :: extract_max(){
    int result = extract_min();
    return result*(-1);
}
int MaxHeap :: maximum(){
    int result = minimum();
    return result*(-1);
}




// Implementing min-max heap
// But i will implement min heap
int main(){
    cout << "Implementation of Min Heap\n";
    MinHeap heap;
    heap.aad_element(50);
    heap.aad_element(16);
    heap.aad_element(17);
    heap.aad_element(8);
    heap.aad_element(550);
    heap.aad_element(2);
    heap.aad_element(2);
    heap.aad_element(99);
    
    cout << heap.extract_min() << "\n";
    cout << heap.extract_min() << "\n";
    cout << heap.extract_min() << "\n";
    cout << heap.extract_min() << "\n";
    cout << heap.extract_min() << "\n";
    cout << heap.extract_min() << "\n";
    cout << heap.extract_min() << "\n";
    cout << heap.extract_min();
    
    cout << "\n\nNow implementation of Max Heap\n";
    cout << "This Implementation has been done using the concept of Inheritance\n";
    MaxHeap Mheap;
    Mheap.aad_element_max(50);
    Mheap.aad_element_max(16);
    Mheap.aad_element_max(17);
    Mheap.aad_element_max(8);
    Mheap.aad_element_max(550);
    Mheap.aad_element_max(2);
    Mheap.aad_element_max(2);
    Mheap.aad_element_max(99);
    //cout << heap.heap[0] << heap.heap[1] << heap.heap[2] << heap.heap[3];
    cout << Mheap.extract_max() << "\n";
    cout << Mheap.extract_max() << "\n";
    cout << Mheap.extract_max() << "\n";
    cout << Mheap.extract_max() << "\n";
    cout << Mheap.extract_max() << "\n";
    cout << Mheap.extract_max() << "\n";
    cout << Mheap.extract_max() << "\n";
    cout << Mheap.extract_max();
    return 0;
}
