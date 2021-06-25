#include<iostream>
#include<queue>
using namespace std;

// Sum of minimum and maximum elements of all subarrays of size k

class maxHp{
public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second<b.second;
    }
};

class minHp{
public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
};

int SumOfKsubArray(int* arr,int n,int k){
    priority_queue<pair<int,int>,vector<pair<int,int>>,maxHp> maxHeap;
    priority_queue<pair<int,int>,vector<pair<int,int>>,minHp> minHeap;

    // {2, 5, -1, 7, -3, -1, -2}
    int answer = 0;
    for(int i = 0 ;i<n ; i++){
        if( i < k-1 ) maxHeap.push({i,arr[i]});
        else{
            while(maxHeap.top().first < i - k + 1){
                maxHeap.pop();
            }
            maxHeap.push({i,arr[i]});
            answer += maxHeap.top().second;
        }
    }

    
    for(int i = 0 ;i<n ; i++){
        if(i < k-1 ) minHeap.push({i,arr[i]});
        else{
            while(minHeap.top().first < i - k + 1){
                minHeap.pop();
            }
            minHeap.push({i,arr[i]});
            answer += minHeap.top().second;
        }
    }
    return answer;
}

// Driver program to test above functions
int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    cout << SumOfKsubArray(arr, n, k) ;
    return 0;
}
