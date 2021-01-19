#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Print all subarrays with sum zero

void printpermutation(vector<int> vec){
    for(int i = 0; i<vec.size(); i++){
        for(int j = i+1; j<vec.size(); j++){
            cout << "Subarray Between  " << vec[i]+1 << " --->>> " << vec[j] << "\n";
        }
    }
}

int main(){
    int arr[] = {6, 3, -1, -3, 4, -2, 2,    //    {0, 1, 2, 3, 4, 5, 6, 7,  8,  9,10}
             4, 6, -12, -7};                // {0, 6, 9, 8, 5, 9, 7, 9, 13, 19, 7, 0}
    int len = sizeof(arr)/sizeof(arr[0]);

    int aggregate = 0;
    map<int,vector<int>> dictionary;
     dictionary[0].push_back(-1);
    for(int i = 0;i<len ; i++){
        aggregate += arr[i];
        dictionary[aggregate].push_back(i);
    }

    map<int,vector<int>> :: iterator itr;
    itr = dictionary.begin();

    while(itr != dictionary.end()){

        if(itr->second.size() > 1){
            printpermutation(itr->second);
        }
        itr++;
    }
    return 0;
}
