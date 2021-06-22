#include<iostream>
#include<queue>
using namespace std;

// Minimum sum of two numbers formed from digits of an array

class comparer{
public:
    bool operator()(int a,int b){
        return a<b;
    }
};

int minSum(int* arr,int n){

    priority_queue<int,vector<int>,comparer> maxHeap;
    int sum = 0;
    int first,second,remainder = 0,digit,factor = 1;
    for(int i = 0; i<n ; i++){
        maxHeap.push(arr[i]);
    }
    if(n%2 == 1){
        maxHeap.push(0);
    }

    while(!maxHeap.empty()){
        
        first = maxHeap.top(); maxHeap.pop();
        second = maxHeap.top(); maxHeap.pop();

        digit = (first + second + remainder)%10;
        remainder = (first + second + remainder)/10;

        sum = digit*factor + sum;
        factor = factor*10;

    }
    sum  = sum + remainder*factor;
    return sum;
}

int main()
{
    int arr[] = {5, 3, 0, 7, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<minSum(arr, n)<<endl;
    return 0;
}
