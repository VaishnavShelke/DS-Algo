#include <iostream>
#include <bits\stdc++.h>

using namespace std;

/**
 * !       Find wether redundant bracket present or not         
 **/

void findRedundant(string str){
    stack<char> stc;
    bool flag = true;
    char temp;
    for(int i =0; i<str.size() ; i++){
        flag = true;
        if(str[i] != ')'){
            stc.push(str[i]);
        }
        else{
            while(!stc.empty() && stc.top()!='(' ){
                temp = stc.top();
                stc.pop();
                if(temp == '+' || temp == '-' || temp == '/' || temp == '*') 
                    flag = false;
            }
            if(flag == true) {
                cout << "YES" << endl;
                return;
            }
            if(!stc.empty()) stc.pop();
        }
    }
    cout << "NO" << endl ;
    return;
}
int main()
{
    string str = "((a+b))";
    findRedundant(str);
 
    str = "(a+(b)/c)";
    findRedundant(str);
 
    str = "(a+b*(c-d))";
    findRedundant(str);
 
    return 0;
}
