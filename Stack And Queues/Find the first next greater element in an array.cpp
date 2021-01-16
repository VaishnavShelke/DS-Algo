#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Find the next-first greater element to the right in an array

int main(){
    int arr[] = {11, 13, 21, 3};
    int len = sizeof(arr)/sizeof(arr[0]);
    stack<int> stc;
    pair<int,int> answers[len];

    for(int i = len-1 ; i>=0 ; i--){
            if(stc.empty()){
                answers[i] = make_pair(arr[i],-1);
                stc.push(arr[i]); 
            }
            else{
                while(!stc.empty() && stc.top()<arr[i]){
                    stc.pop();
                }
                if (stc.empty()) 
                    answers[i] = make_pair(arr[i],-1);
                else
                    answers[i] = make_pair(arr[i],stc.top());
                stc.push(arr[i]);
            }
    }

    for(int i = 0;i<len;i++){
        cout << answers[i].first << "  --->>>  " <<answers[i].second << "\n";
    }
    return 0;
}
