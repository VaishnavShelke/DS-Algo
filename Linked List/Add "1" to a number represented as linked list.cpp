#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//       AAD 1 TO A NUMBER REPRESENTED AS LINKED LIST
//                example:  1999 is represented as   1{head} -> 9 -> 9 -> 9 -> NULL
/*
            Recursion break....
                Recursively traverse to the last node.
                Add 1 to it.....
                find the unit place after addition...
                find the carry term.....
                over write the value at current node by unit...
                return the carry.
            
            
            Carry = add-one(carry->next).....
                add carry to the current node...
                find the unit place ...
                find the carry term ...
                over write the value at current node by unit...
                return carry...
        
*/


class Node{
public:
    int data;
    Node* next = NULL;
    Node(int dat){
        data = dat;
    }
};
Node* aad_one(Node* head);
int aad_element(Node* current);


int main(){
    Node* head;

    head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next = new Node(9);

    head = aad_one(head);

    Node* current = head;
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
}

Node* aad_one(Node* head){
    int carry = 0;
    carry = aad_element(head);
    if(carry == 0)
        return head;
    else{
        Node* carrynode = new Node(carry);
        carrynode->next = head;
        head = carrynode;
        return head;
    }
}

int aad_element(Node* current){
    int carry;
    int replace;
    if (current->next == NULL){
        replace = (current->data + 1)%10;
        carry = (current->data + 1)/10;
        current->data = replace;
        return carry;
    }
    else{
        carry = aad_element(current->next);
        replace = (current->data + carry)%10;
        carry = (current->data + carry)/10;
        current->data = replace;
        return carry;
    }
}
