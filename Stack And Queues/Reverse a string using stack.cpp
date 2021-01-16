#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Reverse a string using stack

int main(){
    string str = "reverse_me_if_you_can";
    stack<int> stc;
    for(int i = 0;i<str.size();i++){
        stc.push(str[i]);
    }
    string str2 = "";
    for(int i = 0;i<str.size(); i++){
        str2 += stc.top();
        stc.pop(); 
    }
    cout << str << " == " << str2;
    return 0; 
}
