#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Check if the linked list is Circular or Not

class Node{
public:
    int data;
    Node* next = NULL;
    Node(int dat){
        data = dat;
    }
};


/*
    2 -> 12 -> 5 -> 4 -> 3 -> 2 ->2 ;
    ^                             |  
    ------------------------------
*/
/*
    Check if a linked list is circular or not
*/

bool check_circular(Node* head){
    Node* start;
    start = head;
    start = start->next;
    while(start != head){
        start = start->next;
        if(start == NULL) return false;
    }
    return true;
}


int main(){
    Node* head1;
    Node* head2;

    head1 = new Node(4);
    head1->next = new Node(8);
    head1->next->next = new Node(10);
    head1->next->next->next = new Node(15);
    head1->next->next->next->next = new Node(18);
    head1->next->next->next->next->next = new Node(20);
    head1->next->next->next->next->next->next = head1;
    

    if(check_circular(head1)){
        cout << "Linked list is Circular";
    }
    else{
        cout << "Linked list is Not Circular";
    }
    
    
    return 0;
}


