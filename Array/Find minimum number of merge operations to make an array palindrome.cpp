// C++ program to find number of operations
// to make an array palindrome
#include <bits/stdc++.h>
using namespace std;


int findMinOps(int* arr,int n){
    int i = 0;
    int count = 0;
    int j = n-1;

    while(j>i){
        if(arr[j] == arr[i]){
            i++; j--;
        }
        else{
            if(arr[i]>arr[j]){
                arr[j-1] = arr[j]+arr[j-1];
                j = j - 1;
            }
            else{
                arr[i+1] = arr[i] + arr[i+1];
                i = i + 1;
            }
            count++;
        }
    }
    return count;
}
int main()
{
    int arr[] = {11, 14, 15, 99};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Count of minimum operations is "
         <<  findMinOps(arr, n) << endl;
    return 0;
}
