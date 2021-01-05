#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Intersection of two sorted linked list


class Node{
public:
    int data;
    Node* next = NULL;
    Node(int dat){
        data = dat;
    }
};

Node* intersection(Node* h1, Node* h2);

int main(){
    Node* head1;
    Node* head2;

    head1 = new Node(4);
    head1->next = new Node(8);
    head1->next->next = new Node(10);
    head1->next->next->next = new Node(14);
    head1->next->next->next->next = new Node(18);
    
    head2 = new Node(2);
    head2->next = new Node(8);
    head2->next->next = new Node(12);
    head2->next->next->next = new Node(14);

    Node* result = intersection(head1,head2);
    Node* current = result;
    
    cout << "Intersection of two linked lists ... \n";
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
}

// 4 -> 8 -> 10 -> 14 ->18  h1
// 2 -> 8 -> 12 -> 14       h2

Node* intersection(Node* h1,Node* h2){
    Node* intersectionhead;
    Node* intersection = new Node(INT_MAX);
    intersectionhead = intersection;
    while(h1 != NULL && h2 != NULL){
        if(h1->data > h2->data){
            h2 = h2->next;
        }
        else if(h1->data < h2->data){
            h1 = h1->next;
        }
        else{
            intersection->next = new Node(h1->data);
            h1 = h1->next;
            h2 = h2->next;
            intersection = intersection->next;
        }
    }
    return intersectionhead->next;
}
