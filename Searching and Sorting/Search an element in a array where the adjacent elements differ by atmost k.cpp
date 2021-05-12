#include <iostream>
#include <bits\stdc++.h>

using namespace std;

// Search an element in a array where the adjacent elements differ by atmost k
int search(int* arr, int length, int number, int diff){
    int i = 0;

    while(i<length){
        if(arr[i] == number){
            return i;
        }
        else{
            i = i + std::abs(arr[i] - number)/diff;
        }
    }
    return -1; // If nothing is found
}



int main(){
    int arr[] = {2, 4, 5, 7, 7, 6};
    int x = 6;
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Element " << x  << " is present at index "
         << search(arr, n, x, k);
    return 0;
}
