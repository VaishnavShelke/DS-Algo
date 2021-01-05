#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Intersection point of two linked list
/*
    2 -> 12 -> 5 -> 4 -> 
                        3 -> 2 ->2 -> NULL;
         20 -> 7 -> 5 ->
*/
/*
    Very - very intellegent approach
            start two pointers from the heads of two linked list 
            from h1 start ptr1
            from h2 start ptr2
            Both of them traverse at the same speed.
            when let us say ptr1 reaches null
                initialise ptr1 again this time from h2
            vice versa with ptr2;

            When both of them meet they meet at the joint/intersection of the two linked list

            Hopefully you can extrapolate this concept to finding the joint in case of three linked list are intersecting
*/

class Node{
public:
    int data;
    Node* next = NULL;
    Node(int dat){
        data = dat;
    }
};

Node* intersectionpoint(Node* h1, Node* h2);

int main(){
    Node* head1;
    Node* head2;

    head1 = new Node(4);
    head1->next = new Node(8);
    head1->next->next = new Node(10);
    head1->next->next->next = new Node(15);
    head1->next->next->next->next = new Node(18);
    head1->next->next->next->next->next = new Node(20);
    head1->next->next->next->next->next->next = new Node(22);
    
    
    head2 = new Node(2);
    head2->next = new Node(8);
    head2->next->next = new Node(12);
    head2->next->next->next = new Node(14);
    head2->next->next->next->next = head1->next->next->next;

    Node* result = intersectionpoint(head1,head2);
    Node* current = result;
    
    cout << "Intersection JOINT of two linked lists ... \n";
    cout << current->data;
    return 0;
}
/*
    2 -> 12 -> 5 -> 4 -> 
                        3 -> 2 ->2 -> NULL;
         20 -> 7 -> 5 ->
*/
Node* intersectionpoint(Node* h1,Node* h2){
    Node* joint;
    Node* ptr1 = h1;
    Node* ptr2 = h2;

    while(ptr1 != ptr2){
        if(ptr1 == NULL){
            ptr1 = h2;
            continue;
        }
        if(ptr2 == NULL){
            ptr2 = h1;
            continue;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

    }
    return joint = ptr1;

}
