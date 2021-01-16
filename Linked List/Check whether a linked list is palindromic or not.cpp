#include<bits/stdc++.h>
#include <iostream>
using namespace std;
 
// Check whether a given singly linked list is palindrome or not

int main(){
    list<char> lst;
    string feed = "vaishnavvansiav";
    for(int i = 0;i<feed.size();i++){
        lst.push_back(feed[i]);
    }

    stack<char> stc;
    list<char> :: iterator itr;

    itr = lst.begin();
    while(itr != lst.end()){
            stc.push(*itr);
            itr++;
    }

    itr = lst.begin();
    while(itr!= lst.end()){
            if(stc.top() == *itr){
                itr++;
                stc.pop();
            }
            else{
                cout << "Not A Palindromic LL ..... ";
                return 0;
            }
    }
    cout << "Yes ...  A Palindromic LL .....";
    return 0;
}
