#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
// REVERSE A STRING

int main(){
    string str =  "vaishnav naresh shelke";
    for(int i = str.size()-1 ; i>= str.size()/2 ;i--){
        swap(str[i],str[str.size()-1-i]);
    }
    cout << "checkout your reversed string\n";
    for(int i = 0 ; i<str.size() ;i++){
        cout<<str[i];
    }
    return 0;
}
