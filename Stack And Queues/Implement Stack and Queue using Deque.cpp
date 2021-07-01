#include<iostream>
#include<deque>
using namespace std;

// Implement Stack using Deque

class Stack{
private:
    deque<int> dq;
public:
    Stack(){}
    void push(int data){ dq.push_back(data);}
    int top(){ return dq.back();}
    void pop(){ dq.pop_back();}
    bool isempty(){ return dq.empty();}
};

class Queue{
private:
    deque<int> dq;
public:
    Queue(){}
    void enque(int data){ dq.push_back(data);}
    int front(){ return dq.front();}
    void dqueue(){ dq.pop_front();}
    bool isempty(){ return dq.empty();}
};


