#include <iostream>
using namespace std;

// Amcat Question Viraj 
 
int longestSubSeg(int a[], int n, int k)
{
    int cnt0 = 0;
    int l = 0;
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0)
            cnt0++;
 
   
        while (cnt0 > k) {
            if (a[l] == 0)
                cnt0--;
            l++;
        }
 
        max_len = max(max_len, i - l + 1);
    }
 
    return max_len;
}

int noWays(int* a,int window_len,int n,int k){
    int count;
    int no_of_ways = 0;
    for(int i = 0; i<=n-window_len ; i++){
        count = 0;
        for(int j = i; j<i+window_len; j++){
            if(a[j] == 0){
                count++;
            }
        }
        if(count <= k){
            no_of_ways++;
        }
    }
    return no_of_ways;
}

int main(){
