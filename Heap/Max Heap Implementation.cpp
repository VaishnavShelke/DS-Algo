#include <bits/stdc++.h>
using namespace std;
/**
 * * Implement a Max over the top of Min heap
 **/

// Implement Min heap;

class objHeap{
private:
    int maxSize; int heapSize;
    
public:
    int* arr;
    objHeap(int maxSize){ this->maxSize = maxSize; arr = new int[maxSize]; heapSize = 0;}
    
    void swap(int* a, int* b){
        int temp; temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void insert(int data){
        if(heapSize == 0){ arr[0] = data; heapSize++;}
        else{
            if(heapSize == maxSize){
                arr[heapSize-1] = data;
            }
            else{
                arr[heapSize] = data;
                heapSize++;
            }
            this->heapiFy();
        }
    }

    void heapiFy(){
        int i = heapSize-1;int parent;
        while(i>0){
            parent = (i-1)/2;
            if(arr[parent] < arr[i]) break;
            this->swap(&arr[parent],&arr[i]);
            i = parent;
        }
    }

    int top(){
        return arr[0];
    }

    void pop(){
        arr[0] = INT_MAX;
        this->swap(&arr[0],&arr[heapSize-1]);
        heapSize--;
        int parent;
        int left ;
        int right ;
        parent = 0;
        while(true){
            left = 2*parent + 1;
            right = 2*parent + 2;    
            
            if(left<heapSize && right<heapSize){
                if(arr[parent] <= arr[left] && arr[parent] <= arr[right]) {break;}
                else{
                    if(arr[left]>arr[right]){
                        swap(&arr[right],&arr[parent]); parent = right;
                    }
                    else{
                        swap(&arr[parent],&arr[left]); parent = left;
                    }
                }
            }
            else if(left<heapSize && right>= heapSize){
                if(arr[left]>=arr[parent]) break;
                else {swap(&arr[parent],&arr[left]); parent = left;}
            }
            else{
                break;
            }

        }
    }
};

class maxHeap : public objHeap{
public:
    maxHeap(int size):objHeap(size){}

    void insertX(int data){
        insert(-1*data);
    }
    int topX(){
        return -1*top();
    }
};


int main(){

    objHeap minHP(20);
    maxHeap maxHP(20);
   
    for(int i = 19; i>=0 ; i--){
        minHP.insert(i);
        maxHP.insertX(i);
    }
    cout << "Min Heap Output ...\n";
    for(int i = 0; i<20 ; i++){
        cout << minHP.top() << " ";
        minHP.pop();
    }
    cout << endl;
    cout << "Min Heap Output ...\n";
    for(int i = 0; i<20 ; i++){
        cout << maxHP.topX() << " ";
        maxHP.pop();
    }


    //cout << minHP.arr[0] << " " << minHP.arr[1] << " "<< minHP.arr[2] << " "<< minHP.arr[3] << " "<< minHP.arr[4] << " ";
}
