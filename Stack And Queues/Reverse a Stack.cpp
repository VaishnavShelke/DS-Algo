#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// Reverse a Stack using recursion
/**
 * !       REVERSE A STACK USING TWO STACK               
 * */


void send_at_bottom(stack<int>* stc,int current){
    if(stc->empty())  stc->push(current);
    else{
        int now = stc->top();
        stc->pop();
        send_at_bottom(stc,current);
        stc->push(now);
    }
    return;
}
void reverse(stack<int>* stc){

    if(stc->empty()) return;
    int current = stc->top();
    stc->pop();
    reverse(stc);
    send_at_bottom(stc,current);
    return;
}
int main(){
    stack<int> stc;
    for(int i = 0; i<3 ; i++) stc.push(i);
    while(!stc.empty()) { cout << stc.top() << " ---->> "; stc.pop();}
    for(int i = 0; i<3 ; i++) stc.push(i);
    cout << endl << endl;
    reverse(&stc);
    while(!stc.empty()) { cout << stc.top() << " ---->> ";stc.pop();}
    return 0;
}
