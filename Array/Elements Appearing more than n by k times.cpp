#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;

// Given an array of size n and a number k, find all elements that appear more than n/k times

class toppers{
    public:
    int number = INT_MAX;
    int count = 0;
};

int main(){
    // total such numbers possible in extreme case
    int arr[] = { 4, 5, 6, 7, 8, 4, 4, 7, 7, 8, 8, 8,8, 5,5,5,5,5,5 ,9 ,9, 10 };
    int len = sizeof(arr)/sizeof(arr[0]); 
    int k = 5,j;

    toppers topk[k-1];

    for(int i = 0; i<len; i++){

        for(j = 0; j<k-1 ; j++){
            if(topk[j].number == INT_MAX){
                topk[j].number = arr[i]; topk[j].count += 1; break;
            }
            else{
                if(topk[j].number == arr[i]) { topk[j].count += 1; break;}
                else{
                    if(topk[j].count == 0){ topk[j].number = arr[i]; topk[j].count = 1; break;}
                }
            }
        }

        if(j == k-1){
            for(j = 0; j<k-1 ; j++){
                topk[j].count -= 1;
            }
        }
    }

    cout << "The toppers and eligible candidates are ... \n";
    for(int i = 0; i< k-1; i++){
        cout << "  " << topk[i].number << "\n";
    }

    // Now check for each topper is he occures more than n/k times

    int counter;
    for(j = 0; j<k-1 ; j++){
        counter = 0;
        for(int i = 0; i<len ; i++){
            if(arr[i] == topk[j].number){
                counter++;
            }
        }
        if(counter > len/k) cout << "\n The number occuring more than n/k == " << "  " << topk[j].number;
    }

    return 0;
}
