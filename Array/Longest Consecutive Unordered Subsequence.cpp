#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Longest Consecutive Subsequence
// The order of the consecutive number need not be increasing or decreasing.
// Do not consider repeating elements

int main(){
    int sequence[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42};
    int len = sizeof(sequence)/sizeof(sequence[0]); 
    sort(sequence,sequence+len);
    int count;
    int longest = 0;
    for(int i = 0;i<len-1 ;i++){
        count = 1;
        while(sequence[i]+1 == sequence[i+1]||sequence[i] == sequence[i+1]){
            if(sequence[i]+1 == sequence[i+1]){
                count++;
            }
            i++;
        }
        longest = max(longest,count);
    }
    cout << "The longest consecutive subsequence is ... "<< longest;
    return 0;
}
