#include <iostream>
#include<queue>
using namespace std;

// K’th Smallest/Largest Element in Unsorted Array 

class maxHeap{
public:
    bool operator()(int a,int b){
        return a<b;
    }
};

int kthSmallest(int* arr,int size, int k){
    priority_queue<int,vector<int>,maxHeap> pq;
    int i = 0;
    while(pq.size() != k){
        pq.push(arr[i]);i++;
    }
    for(   i ; i<size ; i++){
        if(pq.top()>arr[i]){
            pq.pop(); pq.push(arr[i]);
        }
        else{}
    }
    return pq.top();
}

int main()
{
    int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]), k = 5;
    cout << "K'th smallest element is " << kthSmallest(arr, n, k);
    return 0;
}
