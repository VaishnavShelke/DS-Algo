#include<iostream>
#include<bits\stdc++.h>
using namespace std;


int findMaxProfit(vector<vector<int>> arr,int timerem, int jobs,int* memo){

    if(timerem <=  1 || jobs == 0) return 0;
    
    int inclLast; int exclLast;
    if(timerem>=arr[jobs-1][1]){
        if(memo[jobs] != INT_MAX) return memo[jobs];
        inclLast = findMaxProfit(arr,arr[jobs-1][0],jobs-1,memo) + arr[jobs-1][2];
        exclLast = findMaxProfit(arr,timerem,jobs-1,memo);
        memo[jobs] = max(inclLast,exclLast);
        return max(inclLast,exclLast);
    }
    else{
        exclLast = findMaxProfit(arr,timerem,jobs-1,memo);
        memo[jobs] = exclLast;
        return exclLast;
    }
}

// Driver program
bool comparers(const vector<int>& a1,const vector<int>& a2){
    return a1[1]<a2[1];
}

int main()
{
    vector<vector<int>> arr{{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = arr.size();
    sort(arr.begin(),arr.end(),comparers);
    
    int memo[n+1];
    for(int i = 0 ;i<n+1; i++) memo[i] = INT_MAX;
    cout << "The optimal profit is " << findMaxProfit(arr,arr[n-1][1], n,memo);
    return 0;
}



