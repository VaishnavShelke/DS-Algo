#include <iostream>
#include <bits\stdc++.h>

using namespace std;

// Longest Common Subsequence of Three Strings
/*
        Although 2 strings at a time is a better method time complexity
        wise to approach this problem but we will go for creating a 3 dimensional
        array
*/

int main(){
    string X = "AGGT12"; 
    string Y = "12TXAYB"; 
    string Z = "12XBA";

    int xl = X.length(); 
    int yl = Y.length(); 
    int zl = Z.length();

    int longest_com_uptos[xl+1][yl+1][zl+1];

    for(int i = 0; i<=xl ; i++){
        for(int j = 0; j<=yl ; j++){
            for(int k = 0; k<=zl ; k++){
                if(i == 0) {longest_com_uptos[i][j][k] = 0; continue;}
                if(j == 0) {longest_com_uptos[i][j][k] = 0; continue;}
                if(k == 0) {longest_com_uptos[i][j][k] = 0; continue;}

                if(X[i-1] == Y[j-1] && X[i-1] == Z[k-1]){
                    longest_com_uptos[i][j][k] = longest_com_uptos[i-1][j-1][k-1]+1;
                }
                else{
                    longest_com_uptos[i][j][k] = max(longest_com_uptos[i-1][j][k],
                                                                        longest_com_uptos[i][j-1][k]);
                    longest_com_uptos[i][j][k] = max(longest_com_uptos[i][j][k],
                                                                        longest_com_uptos[i][j][k-1]);
                    
                }
            }
        }
    }
    cout << "The length of longest common subsequence in the given three strings is ... " << longest_com_uptos[xl][yl][zl];
}
