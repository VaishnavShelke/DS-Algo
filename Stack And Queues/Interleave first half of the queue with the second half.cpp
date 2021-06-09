#include <iostream>
#include <bits\stdc++.h>
using namespace std;

// Interleave first half of the queue with the second half
//    Use ONLY a single auxiliary satck


void interLeaveQueue(queue<int> &q){

    int halfSize = q.size()/2;
    stack<int> stc;  // Our aim is to stack this stack in such a way that for 
                        //first half of the queue the first element is the top most element
    
    for(int i = 0; i<halfSize; i++){
        stc.push(q.front());
        q.pop();
    }

    while(!stc.empty()){
        q.push(stc.top());
        stc.pop();
    }

    for(int i = 0; i<halfSize; i++){
        q.push(q.front());
        q.pop();
    }

    for(int i = 0; i<halfSize; i++){
        stc.push(q.front());
        q.pop();
    }

    while(!stc.empty()){
        q.push(stc.top());
        stc.pop();
        q.push(q.front());
        q.pop();
    }
    return;
}
int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interLeaveQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
