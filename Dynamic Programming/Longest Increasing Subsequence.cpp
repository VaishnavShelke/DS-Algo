#include <iostream>
#include <bits\stdc++.h>

using namespace std;

// Longest increasing subsequence
/*
    New category of DP problem....{ Till now I have discovered 2}
            Not all DP have time complexity n^2
                    ...like in the below given example the time complexity is actually n*(n - 1)...
*/
/*
    Let us first understand how we would approach this problem
        Suppose we are midway in constructing our answer
        Let our answer be stored in an array longest_Inc_SS_UPTO
            As the name of the array suggests ... the array stores the answer for the
                longest increasing subsequence whose last element is the current element
        
        now lets say we have reached the ith element
        and our arr considered till then is {4, 7,10 ,6} 

        Now we are suppose to add/consider new element 21 to arr

        WE HAVE TO CALCULATE THE MAX LENGTH INCREASING SUBSEQUENCE WHOSE LAST ELEMENT IS 21.

        what we do is we consider every element from 0 -->> (index at 21) - 1
        and whosever has value less than 21 ... let say index j
            We store longest_Inc_SS_UPTO[j] ...

    After running loop we output the maximum of stored longest_Inc_SS_UPTO[j] and add 1 to it

    In case the index 21 is itself the smallest element we assign longest_Inc_SS_UPTO[(index)21] = 1;
*/

int main(){
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int len = sizeof(arr)/sizeof(arr[0]);

    int longest_uptome[len];

    for(int i = 0; i<len ; i++){
        longest_uptome[i] = 1;             // By defalut in case the ith is the lowest of all elements upto it
        for(int j = 0; j<i ; j++){

            if(arr[i] > arr[j] ){
                longest_uptome[i] = max(longest_uptome[i], longest_uptome[j] + 1);
            }
        }
    }

    cout << "The longest inreasing subsequence has length ... " << *max_element(longest_uptome,longest_uptome + len);
    return 0;
}
