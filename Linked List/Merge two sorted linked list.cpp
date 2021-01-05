#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Mearge two sorted linked lists


class Node{
public:
    int data;
    Node* next = NULL;
    Node(int dat){
        data = dat;
    }
};

Node* mearge_sorted_list(Node* h1, Node* h2);

int main(){
    Node* head1;
    Node* head2;

    head1 = new Node(4);
    head1->next = new Node(8);
    head1->next->next = new Node(10);
    head1->next->next->next = new Node(14);
    head1->next->next->next->next = new Node(18);
    
    head2 = new Node(2);
    head2->next = new Node(12);
    head2->next->next = new Node(13);
    head2->next->next->next = new Node(20);

    Node* result = mearge_sorted_list(head1,head2);
    Node* current = result;
    
    cout << "Addition of tow linked list numbers ... \n";
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
}

// 4 -> 8 -> 10 -> 14 ->18  h1
// 2 ->12 -> 13 -> 20       h2

Node* mearge_sorted_list(Node* h1,Node* h2){
    Node* intersection = new Node(INT_MAX);
    Node* mearge = intersection;
    while(h1 != NULL && h2 != NULL){
        if(h1->data > h2->data){
            intersection->next = h2;
            h2 = h2->next;
        }
        else{
            intersection->next = h1;
            h1 = h1->next;
        }
        intersection = intersection->next;
    }
    while(h1 != NULL){
        intersection->next = h1;
        h1 = h1->next;
        intersection = intersection->next;
    }
    while(h2 != NULL){
        intersection->next = h2;
        h2 = h2->next;
        intersection = intersection->next;
    }
    intersection->next = NULL;
    return mearge->next;
}
