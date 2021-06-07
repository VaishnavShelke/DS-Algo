#include<iostream>
#include<bits\stdc++.h>
using namespace std;


// Longest Common Prefix

// Driver program to test above function

bool rightIsWell(string* arr,int size, string shortest,int low,int high){

    for(int j = 0; j<size ; j++){
        for(int i = low ; i<= high; i++){
            if(shortest[i] != arr[j][i]) return false;
        }
    }
    return true;
}

string longestPrefix(string* arr, int size, string shortest){

    int high = shortest.size() - 1; int low = 0;
    int mid; string prefix;

    while(high>low){
        mid = (high + low)/2;

        if(rightIsWell(arr,size,shortest,low,mid)){

            prefix += shortest.substr(low,mid+1);
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return prefix;
}

string commonPrefix(string* arr,int size){

    string shortest;
    int smallLen = INT_MAX; int index; 
    for(int i = 0; i<size ; i++){
        if(arr[i].size()<smallLen){
            index = i; smallLen = arr[i].size();
        }
    }
    shortest = arr[index];

    string prefix;
    prefix = longestPrefix(arr,size,shortest);
    return prefix;
}






int main()
{
    string arr[] = {"geeksforgeeks", "geeks",
                    "igeenk", "geezer"};
    int n = sizeof (arr) / sizeof (arr[0]);
  
    string ans = commonPrefix(arr, n);
  
    if (ans.length())
        cout << "The longest common prefix is "
             << ans;
    else
        cout << "There is no common prefix";
    return (0);
}
