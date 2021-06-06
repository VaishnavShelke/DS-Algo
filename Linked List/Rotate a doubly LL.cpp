#include <iostream>
#include <bits\stdc++.h>
using namespace std;


/**
 * !      ROTATE A DOUBLY LINKED LIST BY N NODES CC                     
 * *                                               
 **/

class Node{
public:
    Node* next;
    int data;
    Node(int data){ next = NULL; this->data = data;}
};

Node* split(Node* head,int n){
    Node* current = head;
    while(n>1){
        current = current->next; n--;
    }
    Node* temp = current->next;
    current->next = NULL;
    return temp;
}
void rotateCC(int n,Node** head){
    Node* current = *head;

    Node* first = current;
    Node* second  = split(current,n);

    *head = second;
    while(second->next != NULL) second = second->next;
    second->next = first;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3); 
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    rotateCC(4,&head);
    Node* current = head;

    while(current != NULL){
        cout << current->data << " "; current = current->next;
    }
    return 0;
}
