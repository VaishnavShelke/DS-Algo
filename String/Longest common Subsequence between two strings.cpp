#include <iostream>
#include <bits\stdc++.h>
#define N 9
using namespace std;


// Longest common Subsequence between two strings

int main() 
{ 
    string str1 = "AGGTAB"; 
    string str2 = "GXTXAYB";   

    int longestUpto[str1.size()+1][str2.size()+1];

    for(int j = 0; j<=str1.size() ; j++){
        for(int i = 0; i<=str2.size() ; i++){
            if(i==0 || j==0) longestUpto[j][i] = 0;
            else if(str1[j] == str2[i]) longestUpto[j][i] = 1 + longestUpto[j-1][i-1];
            else longestUpto[j][i] = max(longestUpto[j-1][i], longestUpto[j][i-1]);
        }
    }

    cout << "Length of longest common subsequence is ... " << longestUpto[str1.size()][str2.size()];
    return 0;
}




