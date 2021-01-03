#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

// Remove from first -- add to first
class mystack{
public:
    Node* head;

    mystack();  // Constructor
    void myappend(int data);
    void myremove();
    void myprint();
};

mystack :: mystack(){
    head = NULL;
}

void mystack :: myappend(int num) {
    Node* temp;
    if (head == NULL){
        head = new Node();
        head->data = num;
        head->next = NULL;
    }
    else{
        temp = new Node();
        temp->data = num;
        temp->next = head;
        head = temp;
    }
}

void mystack :: myprint(){
    Node* pointer;
    pointer = head;
    cout << "Result represents from top to bottom as left to right\n";
    while(pointer != NULL){
        cout << pointer->data << " ";
        pointer = pointer->next;
    }
}

void mystack :: myremove(){
    Node* second;
    if(head == NULL){
        cout << "\nStack is empty...\n";
        return;
    }
    
    else{
        second = head->next;
        head = second;
    }
}

int main(){
    mystack stk;
    stk.myappend(10);
    stk.myappend(20);
    stk.myappend(30);
    stk.myremove();
    stk.myprint();
    return 0;
