#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//      ADD TWO NUMBERS REPRESENTED AS LINKED LIST
//      Note : To represent 122 we represent it like 2 -> 2 -> 1 -> NULL;
/*
           DIY.......
           Clue : In resultant array add a INT_MAX node while declaration
           Append the sums to this
           And remove the INT_MAX node when all operation are complete
*/


class Node{
public:
    int data;
    Node* next = NULL;
    Node(int dat){
        data = dat;
    }
};

Node* add_two_numbers(Node* h1, Node* h2);

int main(){
    Node* head1;
    Node* head2;

    head1 = new Node(9);
    head1->next = new Node(9);
    head1->next->next = new Node(9);
    head1->next->next->next = new Node(9);
    
    head2 = new Node(2);
    head2->next = new Node(2);
    head2->next->next = new Node(1);

    Node* result = add_two_numbers(head1,head2);
    Node* current = result;
    
    cout << "Addition of tow linked list numbers ... \n";
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
}

// 9 -> 9 -> 9          -> 9
// 2 -> 2 -> 1
// 1 -> 2 -> 1{carry 1} -> 0 -> 1

Node* add_two_numbers(Node* h1,Node* h2){

    
    Node* resultant = new Node(INT_MAX);
    Node* current = resultant;
    int addition;
    int unitplace;
    int carry = 0;
    
    while(h1 != NULL && h2 != NULL){
        addition = h1->data + h2->data + carry;
        unitplace = addition%10;
        carry = addition/10;
        current->next = new Node(unitplace);
        current = current->next;
        h1 = h1->next;
        h2 = h2->next; 
    }
    if(h1 == NULL){
        while(h2 != NULL){
            addition = h2->data + carry;
            unitplace = addition%10;
            carry = addition/10;
            current->next = new Node(unitplace);
            current = current->next;
            h2 = h2->next;
        }
    }
    if(h2 == NULL){
        while(h1 != NULL){
            addition = h1->data + carry;
            unitplace = addition%10;
            carry = addition/10;
            current->next = new Node(unitplace);
            current = current->next;
            h1 = h1->next;
        }
    }
    if(carry !=0){
        current->next = new Node(carry);
        
    }
    resultant = resultant->next;
    return resultant;
}
