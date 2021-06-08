#include <iostream>
#include <bits\stdc++.h>
#define N 9
using namespace std;

// Minimum characters to be added at front to make string palindrome

int main(){

    string str = "AACECAAAA";
    string temp = str;
    reverse(temp.begin(),temp.end());
    
    str = str + temp;

    
    // Now in the string str we have to find the longest prefix that is also a suffix;
    // AACECAAAA AAAACECAA
    int lps[str.size()];
    lps[0] = 0;
    int i = 0,k;
    
    for(int j = 1; j<str.size() ; j++){
        
        if(str[i] == str[j]){
            lps[j] = i+1;
            i++;
        }
        else{
            k = j;
            while(i != 0&& str[i] != str[j]){
                i = lps[k-1];
                k = i;
            }
            if(str[i] == str[j]) lps[j] = i+1;
            else lps[j] =  0;
        }
    }
    

    for(int i = 0 ; i<str.size() ; i++){
        cout<< str[i] << " ";
    } 
    cout << endl;
    for(int i = 0 ; i<str.size() ; i++){
        cout<< lps[i] << " ";
    }

    cout << "\n\nMinimum characters to be added at front to make string palindrome ... " << str.size()/2 - lps[str.size()-1];
    return 0;
}
