#include<iostream>
#include<bits\stdc++.h>

using namespace std;

//Minimum removals from array to make max – min <= K

int countRemovals(int* start,int* end,int k){
    if(start == end) return -99999;
    
    int removals;
    if(*(end-1) -*(start) > k)
        removals = 1 + min(countRemovals(start+1,end,k),countRemovals(start,end-1,k));
    else
        removals = 0;
    return removals;
}

int removals(int* a,int n, int k){
    return countRemovals(a,a+n,k);
}
int main()
{
    int a[] = {1, 3, 4, 9, 10,
               11, 12, 17, 20};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a,a+n);
    int k = 4;
    cout << removals(a, n, k);
    return 0;
}
