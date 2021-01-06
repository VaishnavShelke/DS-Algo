#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Delete the nodeS with a given key in the circular linked list

class Node{
public:
    int data;
    Node* next = NULL;
    Node(int dat){
        data = dat;
    }
    Node();
};


/*
    2 -> 12 -> 5 -> 4 -> 5 -> 2 ->2 ;   ||      
    ^                             |     ||    Delete all nodes with key value as 5
    ------------------------------      ||    And what if the starting node itself is to be deleted???
*/
/*
    Split a circular linked list into two halves
*/

Node* delete_key(Node* Chead,int key){
    Node* current = Chead->next;
    Node* previous = Chead;
    Node* next = current->next;

    while(current != Chead){
        if(current->data == key){
            previous->next = next;
            current = next;
            next = next->next;
            }
        else{
            previous = current;
            current = next;
            next = next->next;
        }
    }
    if(current->data == key){
        previous->next = next;
        Chead = next;                // Add condition when the entire loop itself has value == key
    }
    return Chead;
}
int main(){
    Node* head1;

    // 4 -> 8 ->10 ->15 ->18 ->20 -> ->30 -> 4Head
    head1 = new Node(1);
    head1->next = new Node(15);
    head1->next->next = new Node(15);
    head1->next->next->next = new Node(15);
    head1->next->next->next->next = new Node(15);
    head1->next->next->next->next->next = new Node(15);
    head1->next->next->next->next->next->next = new Node(15);
    head1->next->next->next->next->next->next->next = head1;
    
    Node* result =  delete_key(head1,15);
    
    Node* ptr;

    ptr = result->next;
    cout<< "Circular list after deletion ..... \n" << result->data <<" ";
    while(ptr != result){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    return 0;
}
