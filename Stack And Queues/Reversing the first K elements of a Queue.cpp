#include<iostream>
#include<bits\stdc++.h>
using namespace std;

// Reversing the first K elements of a Queue

void reverseQueueFirstKElements(int k,queue<int>& Queue){
    stack<int> stc;int temp;

    for(int i = 0; i<k ; i++){
        stc.push(Queue.front());
        Queue.pop();
    }

    while(!stc.empty()){
        Queue.push(stc.top());
        stc.pop();
    }

    for(int i = 0; i < Queue.size() - k; i++){
        temp = Queue.front();
        Queue.pop();
        Queue.push(temp);
    }

}
void Print(queue<int>& Queue)
{
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}
int main()
{
    queue<int> Queue;
    Queue.push(10);
    Queue.push(20);
    Queue.push(30);
    Queue.push(40);
    Queue.push(50);
    Queue.push(60);
    Queue.push(70);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);
 
    int k = 5;
    reverseQueueFirstKElements(k, Queue);
    Print(Queue);
}
