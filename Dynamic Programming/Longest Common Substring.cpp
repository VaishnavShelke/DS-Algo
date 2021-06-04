#include <bits/stdc++.h>
#include<iostream>
using namespace std;

// Longest Common Substring
// Contigiius substring

int LCSunStr(char* NN,char* MM, int N, int M){

    int substrLen[N+1][M+1];  // Stores the value of maximum common substring ending at n,m
    int result = INT_MIN;
    for(int n = 0; n<=N ; n++){
        for(int m = 0; m<=M ; m++){
            
            if(m == 0 || n == 0) substrLen[n][m] = 0; 
            else if(MM[m-1] != NN[n-1]){
                substrLen[n][m] = 0;
            }      
            else{
                substrLen[n][m] = substrLen[n-1][m-1]+1;
                result = max(result,substrLen[n][m]);
            }     
        }
    }
    return result;
}
int main()
{
    char X[] = "OldSite:GeeksforGeeks.org";
    char Y[] = "NewSite:GeeksQuiz.com";
 
    int m = strlen(X);
    int n = strlen(Y);
 
    cout << "Length of Longest Common Substring is "
         << LCSunStr(X, Y, m, n);
    return 0;
}
