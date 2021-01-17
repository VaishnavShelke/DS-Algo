#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// First In First Out
class node{
public:
    int data;
    node* next = NULL;
    node* prev = NULL; 
    node();
    node(int dat) { data = dat;}
};

class mydoublyLL{
public:
    node* head;
    node* rear;
    mydoublyLL(){head = NULL;rear = NULL;}

    void myappend(int num); // add from front;
    void myremove();        // remove from back;
    void myprint();
    void reverselinkedlist();
};

void mydoublyLL :: myappend(int num){
    if(head == NULL){
        head = new node(num);
        rear = head;
        return;
    }
    else{
        node* newnode = new node(num);
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void mydoublyLL :: myremove(){
    if(head == NULL){
        cout << "Doubly Linked list already empty\n";
        return;
    }
    else{
        // Remove from the rear
        if(rear->prev == NULL){rear = NULL;head == NULL; return;}
        rear = rear->prev;
        rear->next = NULL;
    }
}

void mydoublyLL :: myprint(){
    
    node* current = head;
    cout << "This is your doubly linked list\n";
    if(current == NULL){cout << "Empty list ...\n";}
    while(current != NULL){
        cout<< current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

void mydoublyLL :: reverselinkedlist(){
    node* current = head;
    node* prev = NULL;
    node* nxt = current->next;
    
    while(true){
        current->next = prev;
        current->prev = nxt;
        prev = current;
        current = nxt;
        if(current == NULL) break;
        nxt = nxt->next;
    }
    node* temp;
    temp = head;
    head = rear;
    rear = temp;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int sizearr = sizeof(arr)/sizeof(arr[0]);
    mydoublyLL doubleLL;
    for(int i = 0;i<sizearr;i++){
        doubleLL.myappend(arr[i]);
    }
    doubleLL.myprint();
    doubleLL.reverselinkedlist();
    doubleLL.myprint();
    return 0;
}
