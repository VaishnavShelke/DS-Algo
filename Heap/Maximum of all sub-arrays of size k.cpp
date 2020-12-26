#include <bits/stdc++.h>
using namespace std;

// Sliding window problem
// Given a array of length l and a window width k
    //find the largest element in the sliding window
    
/* We do this by implementing deque;
 deque is constructed is suc that it follows the following rules
    1. The index of largest element is at the first {and all indexes to the right of given element should be indexes of smaller size}
    2. At the first shoud be only the index which lies in sliding window range else
     should be discarded.
    So after forming the first window in que in decreasing order of the index values;
    print the front {largest} element.
    After this check for the first element in the que and see if it lies in the sliding windlow range, else pop it out
    now aad the k+1 element to the que retaining the law of queue
*/
    
int main(){
    deque<int> dqe;
    int arr[]  = {3,4,53,2,4,54,76,85,4,3,342,33,3,33,3,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    for(int i = 0 ; i<k ; i++) {
        while(!dqe.empty() && arr[dqe.back()] < arr[i]){
            dqe.pop_back();
        }
        dqe.push_back(i);
    }
    cout << arr[dqe.front()] << " ";
    for(int i= k; i<len ; i++){
        while(!dqe.empty() && dqe.front() <= i-k){
            dqe.pop_back();
        }
        while(!dqe.empty() && arr[dqe.back()] < arr[i]){
            dqe.pop_back();
        }
        dqe.push_back(i);
        cout << arr[dqe.front()] << " ";
    }
} 
