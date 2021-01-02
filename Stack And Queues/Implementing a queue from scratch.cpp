
#include<iostream>
using namespace std;

// Implementation of queue using a linked list

class Node{
public:
    int data;
    Node* next;
    Node(){
        next = NULL;
    }
};

class MyQueue{
public:
    Node* front;
    Node* rear;
    int queuesize =  0;

    MyQueue();
    void myenqueue(int data);
    void mydequeue();
    int queuesizes() { return queuesize;}
    int myfirst() {return front->data;}
};

MyQueue :: MyQueue(){
    front = NULL;
    rear = NULL;
}

void MyQueue :: myenqueue(int num){
    Node* temp;
    temp = new Node;
    temp->data = num;
    cout << "New data added == "<< num << "\n";
    if(front == NULL){
        front = temp;
        rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
    queuesize += 1;
}

void MyQueue :: mydequeue(){
    
    if(front == NULL){
        cout << "\nQueue is already empty\n";
        return;
    }
    else{
        cout << "Data deleted == "<<myfirst() << "\n";
        front = front->next;
    }
    queuesize += 1;
}

int main(){
    MyQueue MQ;

    MQ.myenqueue(10);
    MQ.myenqueue(20);
    MQ.myenqueue(30);
    MQ.mydequeue();
    MQ.mydequeue();
    MQ.mydequeue();
    MQ.mydequeue();
    return 0;
    
}
