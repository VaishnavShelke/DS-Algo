#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// Check wether a string is palindrome or not
// AVALIABLEELBAILAVA
int main(){
    string str =  "AVALIABLEELBAILAVA";
    for(int i = str.size()-1 ; i>= str.size()/2 ;i--){
        if(str[i] != str[str.size()-1-i]){
            cout << "sequence not palindromic\n";
            return 0;
        }
    }
    
    cout<< "sequence is a palindrome";
    return 0;
}
