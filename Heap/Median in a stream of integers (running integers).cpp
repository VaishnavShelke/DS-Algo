#include<iostream>
#include<vector>
#include<queue>
using namespace std;



class minHp{
public:
    bool operator()(int a,int b){
        return a>b;
    }
};

class maxHp{
public:
    bool operator()(int a,int b){
        return a<b;
    }
};

void addEntry(int entry,priority_queue<int,vector<int>,maxHp>& maxHeap,priority_queue<int,vector<int>,minHp>& minHeap){
    // {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    if(entry < maxHeap.top()){
        if(maxHeap.size()>minHeap.size()){
            int maxHptop = maxHeap.top(); maxHeap.pop();
            maxHeap.push(entry);
            minHeap.push(maxHptop);
        }
        else{
            maxHeap.push(entry);
        }
    }
    else{
        if(entry < minHeap.top()){
            if(maxHeap.size()>minHeap.size()){
                minHeap.push(entry);
            }
            else{
                maxHeap.push(entry);
            }
        }
        else{
            if(maxHeap.size()>minHeap.size()){
                minHeap.push(entry);
            }
            else{
                int topMin = minHeap.top(); minHeap.pop();
                minHeap.push(entry);
                maxHeap.push(topMin);
            }

        }
    }
}

void printMedian(int* A,int size){
    priority_queue<int,vector<int>,minHp> minHeap;
    priority_queue<int,vector<int>,maxHp> maxHeap;

    maxHeap.push(min(A[0],A[1]));
    cout << A[0] << " ";
    minHeap.push(max(A[0],A[1]));
    cout << (maxHeap.top() + minHeap.top())/2 << " ";
    for(int i = 2; i<size ; i++){
        addEntry(A[i],maxHeap,minHeap);
        if((i+1)%2 == 0){
            cout << (maxHeap.top() + minHeap.top())/2 << " ";
        }
        else{
            cout << maxHeap.top() << " ";
        }
    }
}


int main()
{
    int A[] = { 7, 3, 5, 2};
    int size = sizeof(A)/sizeof(A[0]);
  
    // In lieu of A, we can also use data read from a stream
    printMedian(A, size);
  
    return 0;
}
