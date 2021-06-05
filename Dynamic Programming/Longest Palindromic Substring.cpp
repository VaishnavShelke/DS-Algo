#include <iostream>
#include <bits\stdc++.h>
using namespace std;


/**
 * !                    Longest Palindromic Substring                                        
 * *                                               
 **/

int main(){
    string str1 = "sdksjhshdjsdkjsdbcwjbecnjkcdncjsdjcecjndkjc";
    string str2 = str1;
    reverse(str2.begin(),str2.end());
    int endIndex;
    int lengthEndingAt[str1.size()+1][str1.size()+1];
    int longestSubStr = 0;
    for(int j = 0; j<=str1.size() ; j++){
        for(int i = 0; i<=str1.size() ; i++){
            if(j == 0|| i == 0) lengthEndingAt[j][i] = 0;
            else if(str1[i-1] != str2[j-1]) lengthEndingAt[j][i] = 0;
            else{
                lengthEndingAt[j][i] = 1 + lengthEndingAt[j-1][i-1];
            }
            if(lengthEndingAt[j][i]>longestSubStr){
                longestSubStr = lengthEndingAt[j][i];
                endIndex = i;
            }
        }
    }

    cout << "The longest palindrome is ... " ;
    for(int i = endIndex-longestSubStr; i < endIndex; i++)
        cout << str1[i];
    return 0;
}
