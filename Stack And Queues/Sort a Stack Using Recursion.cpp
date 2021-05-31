#include <bits/stdc++.h>
#include<iostream>
#include<conio.h>
using namespace std;
void stc_reverse(stack<int>* stc);
int main(){
    stack<int> stc;
    stc.push(6); stc.push(3); stc.push(7); stc.push(8); stc.push(1);

    stc_reverse(&stc);

    while(!stc.empty()) {cout << stc.top() << " --->> "; stc.pop();}
    return 0;
}
void send_at_correct(stack<int>* stc,int current){ 
    if(stc->empty()) {stc->push(current);}
    else if (stc->top()<current) {stc->push(current);}
    else{
        int now = stc->top();
        stc->pop();
        send_at_correct(stc,current);
        stc->push(now);
    }
    return;
}
void stc_reverse(stack<int>* stc){

    if(stc->empty()) return;
    int current = stc->top();
    stc->pop();
    stc_reverse(stc);
    send_at_correct(stc,current);
    return;
}



