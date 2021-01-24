#include <iostream>
#include <bits\stdc++.h>

using namespace std;


// Longest subsequence such that the difference between adjacent is one

int main(){
    int arr[] = {1, 2,2,4,5,7,2,34,3,5,3,53,5,4,6,75,54, 3, 4, 5, 3, 2};
    int len = sizeof(arr)/sizeof(arr[0]);

    int longestSSinclme[len];

    for(int i = 0; i<len ; i++){
        longestSSinclme[i] = 1;
        for(int j = 0; j<i ; j++){
                if(std::abs(arr[i]-arr[j]) == 1){
                    longestSSinclme[i] = max(longestSSinclme[i],longestSSinclme[j]+1);
                }
        }
    }
    cout << "The longest subsequence having adjacent elements having absolute difference ... " << *max_element(longestSSinclme,
                                                                                                                longestSSinclme + len);
    return 0;
}
