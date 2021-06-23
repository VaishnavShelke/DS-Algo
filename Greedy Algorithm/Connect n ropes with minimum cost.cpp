#include<iostream>
#include<queue>
using namespace std;
 
#define N 4

class minHeap{
public:
    bool operator()(int a,int b){
        return a>b;
    }
};

int minCost(int* arr,int size){

    priority_queue<int,vector<int>,minHeap> minHp;
    for(int i = 0; i<size ; i++){
        minHp.push(arr[i]);
    }

    int cost = 0;
    int first,second;

    while(minHp.size() != 1){
        first = minHp.top(); minHp.pop();
        second = minHp.top(); minHp.pop();
        cost += first + second;
        minHp.push(first+second);
    }
    return cost;
}

int main()
{
    int len[] = { 4, 3, 2, 6 };
    int size = sizeof(len) / sizeof(len[0]);
    cout << "Total cost for connecting ropes is "
         << minCost(len, size);
    return 0;
}
