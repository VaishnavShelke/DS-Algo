#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// FINDING THE STARTING POINT OF LOOP IN LINKED LIST
// FLOYD LOOP DETECTION ALGORITHM

/*
    Find the first point of intersection of slow and its two times faster counterpart
    ...fast;
    Now....
        loop_start_dist{m} + no_of_cycles_byfast{x}*loop_length{L} + {k}
            == 2*(m + no_of_cycles_byslow{y}*L + {k})
        ... Distance equation
        Output is that 
        m + k is a mutiple of loop length L;
    Therefore if two elements one from head and another from m + k;
    move at same speed they will meet at the staring of the loop; 
*/

class Node{
public:
    int data;
    Node* next = NULL;
    Node(int dat) {
        data = dat;
    }
};
Node* starting_point(Node* head);
int main(){
    Node* head;
    
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(18);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(1e6);

    // Making a loop -->>>

     head->next->next->next->next->next->next->next = head->next->next;

     // Loop made --->>>
    
    Node* pointer = starting_point(head);
    cout << "The starting point in the loop is ... "<<pointer->data;
    return 0;
}

Node* starting_point(Node* head){
        Node* slow = head->next;
        Node* fast = head->next->next;

        while(slow!=fast){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* ele_inloop = slow;
        Node* outloop = head;
        while(ele_inloop != outloop){
            ele_inloop = ele_inloop->next;
            outloop = outloop->next;
        }
        Node* startpoint = outloop;
        return startpoint;
}
