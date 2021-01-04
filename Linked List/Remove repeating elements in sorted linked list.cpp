#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// REMOVE REPEATING ELEMENTS IN SORTED ARRAYS;
/*
        Simple approach:
                Use firstoccurence as the reference point for storing the first occurence of the element
*/

class Node{
public:
    int data;
    Node* next = NULL;
    Node(int dat) {
        data = dat;
    }
};

void removerepeating(Node* head);

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
    
    // Remove repeating elements 
   
    removerepeating(head);
    
    Node* current;
    current = head;
    cout << "All repeating elements removed ...\n";
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
}

void removerepeating(Node* head){
    Node* current = head;
    Node* firstoccurence;
    while(current != NULL){
            
            firstoccurence = current;
            while(current->data == firstoccurence->data){
                current  = current->next;
                if (current == NULL){
                break;
            }
            }
            firstoccurence->next = current;
    }
    return;
    // 1 -> 2 -> 3 -> 3 -> 3 -> 6 -> 8 -> 8 -> 9
}
