#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int ulimit;
vector<int> ultans;
bool masterkey = false;
// Find four numbers that sum to a given value
// Backtracking Approach But with great optimisation by Sorting The Input Array

void backtrack(vector<int> arr,int current,vector<int> answer,int sum);
int main(){
    int sum = 23;
    vector<int> arr = {10, 2, 3, 4, 5, 9, 7, 8} ;
    ulimit = 4;
    vector<int> answer;
    backtrack(arr,0,answer,sum);
    for(int i = 0;i <  ultans.size();i++){
        cout << ultans[i] << " ";
    }
    return 0;
}

void backtrack(vector<int> arr,int current,vector<int> answer,int sum){
    
    if(masterkey){
        return;
    }
    
    if(sum == 0 && answer.size() == ulimit){
        ultans = answer;
        masterkey = true;
        return;
    }
    if(current >= arr.size() || answer.size() >= ulimit || sum <=0){
        return;
    }

    for(int i = 0; i<2 ; i++){
        if(i == 1){
            backtrack(arr,current + 1,answer,sum);
        }
        else{
            int temp = arr[current];
            answer.push_back(arr[current]);
            backtrack(arr,current + 1,answer,sum - temp);
            answer.pop_back();
        }
    }
    return;
}

