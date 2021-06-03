#include <iostream>
#include <bits\stdc++.h>

using namespace std;

/**
 * !           Length of the longest valid substring       
 **/

int main(){
    string strn = "(()())))(())";
    string str = "";
    stack<char> barcStc;
    stack<int> numStc;
    
    int prev;
    str =  str +')' + strn + '(';
    


    for(int i = 0; i<str.size() ; i++){
        if(str[i] == '('){
            barcStc.push('(');
            numStc.push(i);
        }
        else{
            if(barcStc.empty()){
                if(str[i] == ')'){
                    numStc.push(i);
                }
                else{ 
                    barcStc.push('(');
                    numStc.push(i);
                }
            }
            else{
                if(str[i] == ')'){
                    numStc.pop();
                    barcStc.pop();
                }
                else{
                    numStc.push(i);
                    barcStc.push('(');
                }
            }
        }
    }
    int current;
    int Maxima = -99999;
    while(!numStc.empty()){
            current = numStc.top();
            numStc.pop();
            if(!numStc.empty()) {
                prev = numStc.top();
                Maxima = max(Maxima,current-prev);
            }
        }
    cout<< "The length of the longest valid substring is ...  ";
    cout<< Maxima-1;
    return 0;
}
