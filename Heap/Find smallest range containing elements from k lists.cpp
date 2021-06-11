#include <bits/stdc++.h>
using namespace std;
#define N 5

// Find smallest range containing elements from k lists
class comparer{
public:
    bool operator()(tuple<int,int,int> a1,tuple<int,int,int> a2){
        return get<2>(a1) > get<2>(a2);
    }
};

void findSmallestRange(int arr[][N],int n,int k){
    

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,comparer> pq;

    int maxi = INT_MIN;

    for(int i = 0; i<k ; i++){
        maxi = max(maxi,arr[i][0]);
        pq.push({i,0,arr[i][0]});
    }

    int minDiff = INT_MAX;
    pair<int,int> incRange;
    tuple<int,int,int> bottom;
    tuple<int,int,int> newAdd;
    int first,second,third;

    while(!pq.empty()){

        bottom = pq.top();

        first = get<0>(bottom); second = get<1>(bottom);

        if(maxi - arr[first][second] < minDiff){
            minDiff = maxi - arr[first][second];
            incRange = {arr[first][second],maxi};
        }
        pq.pop();
        if(second+1<N){
            newAdd = {first,second+1,arr[first][second+1]};
            maxi = max(maxi,arr[first][second+1]);
        }
        else break;
        pq.push(newAdd);
    }

    cout << "The Samllest Range is ... " << incRange.first << " --->> " << incRange.second;
    return;

}
// Driver program to test above function
int main()
{
    int arr[][N] = {
        { 4, 7, 9, 12, 15 },
        { 0, 8, 10, 14, 20 },
        { 6, 12, 16, 30, 50 }
    };
 
    int k = sizeof(arr) / sizeof(arr[0]);
 
    findSmallestRange(arr, N, k);
 
    return 0;
}
