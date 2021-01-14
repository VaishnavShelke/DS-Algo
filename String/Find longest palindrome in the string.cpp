#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Longest palindromic sequence
// Unique dynamic programming problem
/*
    Step 1.     Reverse the given string and save to strrev
    Step 2.     Find the longest common word string in both the str and strrev
    Step 3.     Done.
*/
/*
        Dynamic programming approach to find the LENGTH of longest common word
        Let us say we have two words
            forgest  -->> l
            soreorg  -->> m
        Now read carefully.....
            The DP matrix find_longest_common_str_ending_at{l and m reps}...
            represents the longest sub string ending at l and m in "forgest" and "soreorg" respectively
            {somewhat similar to Kadane's array}
        Now assume we are at l == 7
                        and  m == 7
        Now element at l != m therefore there is no common string ending at l and m in resp strings
        therefore the find_longest_common_str_ending_at[l][m] = 0;

        if element at l == m;
                then find_longest_common_str_ending_at[l][m] = 1 + find_longest_common_str_ending_at[l-1][m-1]

    The maximum number in the matrix [l][m] is our answer.... :) :)
*/

int main(){
    string str = "forgeeksskeegfor";
    string strr = str;
    int maxima = 0;
    reverse(strr.begin(),strr.end());
    int len = str.size();
    int longestupto[len+1][len+1];
    
    for(int j = 0;j<= len;j++){
        for(int i = 0;i<= len;i++){
            if(j==0){longestupto[j][i] = 0;continue;}
            if(i==0){longestupto[j][i] = 0;continue;}

            if(str[j-1]!=strr[i-1]){
                longestupto[j][i]=0;
            }
            else{
                longestupto[j][i] = 1 + longestupto[j-1][i-1]; 
            }
            maxima = max(maxima,longestupto[j][i]);
        }
    }
    
    cout <<"The length of the longest palindrome is " << maxima;

}
