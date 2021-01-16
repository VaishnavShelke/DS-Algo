#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Find the minimum number of brackets reversal required to balance them all

int main(){
    string paranthesis = "}{{}}{{{";
    stack<char> stc;
    int count = 0;
    for(int i = 0;i<paranthesis.size();i++){
        if(stc.empty()){
            if(paranthesis[i] == '}')
                { stc.push('{'); count++;}
            else stc.push('{');
        }
        else{
            if(paranthesis[i] == '}'){
                stc.pop();
            }
            else{ // paranthesis[i] == '{'
                stc.push(paranthesis[i]);
            }
        }
    }
    int remaining;
    
    if(!stc.empty()){
        remaining = stc.size();
        if(remaining%2 == 1){
            cout << "Not possible to balance";
        }
        else{
            count = count + remaining/2;
            cout << "Minimum number of reversals are ..... " << count;
        }
    }
    else{
        cout << "Minimum number of reversals are ..... " << count;
    }

    return 0;
}
