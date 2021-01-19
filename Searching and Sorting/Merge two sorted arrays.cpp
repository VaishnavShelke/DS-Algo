#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Mearge two sorted arrays
// Using the fact that the keys in a map/dictionary are by default sorted

int main(){
    int arr1[] = { 1, 3, 4, 5};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {2, 4, 6, 8};
    int len2 = sizeof(arr2)/sizeof(arr2[0]);

    map<int,int> dictionary;
    for(int i = 0;i<len1; i++){
        dictionary[arr1[i]] += 1;
    }
    for(int i = 0;i<len2; i++){
        dictionary[arr2[i]] += 1;
    }

    map<int,int> :: iterator itr;
    itr = dictionary.begin();

    cout << "The mearged array is ... ";
    while(itr != dictionary.end()){
        for(int i = 0; i < itr->second; i++){
            cout << itr->first << " ";
        }
        itr++;
    }
    return 0;
}
