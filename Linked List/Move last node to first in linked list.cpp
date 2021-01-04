#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Move last node to front;
// Move LAST NODE / LAST NODE to front;

class Node{
public:
    int data;
    Node* next = NULL;
    Node(int dat) {
        data = dat;
    }
};

Node* last_to_first(Node* head);

int main(){
    Node* head;
    
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    
    head = last_to_first(head);

    Node* current = head;
    while(current != NULL){
        cout << current->data << " ";
        current = current->next; 
    }
    return 0;
}

Node* last_to_first(Node* head){
    Node* last_element;
    Node* current = head;
    while(current->next->next != NULL){    // ----- 3-> 4-> 5-> NULL
        current = current->next;
    }
    last_element = current->next;
    current->next = NULL;
    // Last element found list terminated

    // Aad to front;
    last_element->next = head;
    head = last_element;
    return head;
}
