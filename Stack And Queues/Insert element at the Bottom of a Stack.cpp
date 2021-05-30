#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// INSERTING AT THE END OF THE STACK

void insertAtBottom(int insert,stack<int>* stc){
    if(stc->empty()) stc->push(insert);
    else{
        int current = stc->top();
        stc->pop();
        insertAtBottom(insert,stc);
        stc->push(current);
    }
    return;
}
int main(){
    stack<int> stc;
    for(int i = 0; i<10 ; i++) stc.push(i);

    insertAtBottom(6969,&stc);
    while(!stc.empty()) { cout << stc.top() << " --->> " ; stc.pop();}
}
