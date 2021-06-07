#include<iostream>
#include<bits\stdc++.h>
using namespace std;

// Reversing a queue using recursion


void reverseQueue(queue<long long int>& Queue){

    int current = Queue.front();
    Queue.pop();
    if(!Queue.empty())  reverseQueue(Queue);
    Queue.push(current);

}

void printQueue(queue<long long int> Queue)
{
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

int main()
{
    queue<long long int> Queue;
    Queue.push(56);
    Queue.push(27);
    Queue.push(30);
    Queue.push(45);
    Queue.push(85);
    Queue.push(92);
    Queue.push(58);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);
    reverseQueue(Queue);
    printQueue(Queue);
}

