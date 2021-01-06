#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Split a circular linked list into two circular linked list

/*
    Tortoise and Hare Technique.

    Tortoise completes the circle in 2 the steps than the hare

    Therefore when the hare reaches at the head of the circular linked list tortoise at the middle of
    the circular linked list
*/

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
    2 -> 12 -> 5 -> 4 -> 3 -> 2 ->2 ;   ||      
    ^                             |     ||
    ------------------------------      ||
*/
/*
    Split a circular linked list into two halves
*/

pair<Node*,Node*> split_circular(Node* head){
    Node* tortoise = head;Node* hare = head;

    Node* end1;Node* end2;Node* beg1;Node* beg2;

    while(true){
        if(hare->next == head){
            end2 = hare;end1 = tortoise;

            beg2 = tortoise->next;beg1 = head;
            break;
        }
        if(hare->next->next == head){
            end2 = hare->next;end1 = tortoise;
            
            beg2 = tortoise->next;beg1 = head;
            break;
        }
        hare = hare->next->next;
        tortoise = tortoise->next;
    }

    // Close loops
    end2->next = beg2;
    end1->next = beg1;
    pair<Node*,Node*> result = make_pair(beg1,beg2);
    return result;
}


int main(){
    Node* head1;

    // 4 -> 8 ->10 ->15 ->18 ->20 -> ->30 -> 4Head
    head1 = new Node(4);
    head1->next = new Node(8);
    head1->next->next = new Node(10);
    head1->next->next->next = new Node(15);
    head1->next->next->next->next = new Node(18);
    head1->next->next->next->next->next = new Node(20);
    head1->next->next->next->next->next->next = new Node(30);
    head1->next->next->next->next->next->next->next = head1;
    
    pair<Node*,Node*> result = split_circular(head1);

    Node* loop1 = result.first;
    Node* loop2 = result.second;
    Node* ptr;

    ptr = loop1->next;
    cout<< "Loop 1 ..... \n" << loop1->data << " ";
    while(ptr != loop1){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
     
    ptr = loop2->next;
    cout<< "\nLoop 2 ..... \n" << loop2->data << " ";
    while(ptr != loop2){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    return 0;
}
