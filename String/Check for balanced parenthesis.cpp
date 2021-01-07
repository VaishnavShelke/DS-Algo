#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// Check for balanced parenthesis

bool anyonefrom(char character);

int main(){
    string paranthesis = "{[{}]}{{{}}}";
    map<char,char> par;
    par['{'] = '}';par['['] = ']';par['('] = ')';

    stack<char> stc;
    char ob = '{';
    for(int i = 0;i<paranthesis.size(); i++){
        if(stc.empty()){
            stc.push(paranthesis[i]);
        }
        else{
            if(paranthesis[i] == par[stc.top()]){
                stc.pop();
            }
            else if(anyonefrom(paranthesis[i])){
                stc.push(paranthesis[i]);
            }
            else{
                cout << "Unbalanced .....\n";
                return 0;
            }
        }
    }
    if(stc.empty()) {cout << "Balanced .....";}
    else {cout << "Unbalanced .....";}
    return 0;
}

bool anyonefrom(char character){
    string str = "{[(";
    for(int i = 0;i<str.size(); i++){
        if(str[i] == character){
            return true;
        }
    }
    return false;
}
