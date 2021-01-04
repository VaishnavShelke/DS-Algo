#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
    Finding the loop length.....
        The approach is to first find out any element in the loop
        This can be done using Floyd Cycle detection Algorithm.

        After the slow and fast pointer point at the same location
        Save that location in the start pointer
        run a loop from start to the next till start is reached again
        and count the elements in the linked list

    Finding the starting node of the loop....
        Start two pointers of equal speed.
        One from head and another from kth node
        It is certian that both of them will reach the starting node
        of the loop.
    
    Now you know what needs to be done next....
            Proof:
                start_position + X = K;
                X + pointer_from_kth_to_start = K;
*/
class Node{
public:
    int data;
    Node* next = NULL;
    Node(int dat) {
        data = dat;
    }
};
void remove_loop(Node* head);
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
    remove_loop(head);
    Node* pointer;
    pointer = head;
    while(pointer!= NULL){
        cout << pointer->data << " ";
        pointer = pointer->next;
    }
    return 0;
}

void remove_loop(Node* head){
        Node* slow = head;
        Node* fast = head->next->next;

        while(slow!=fast){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* element_in_loop = slow;
        cout << "Found the element in the loop....\n";
        // Found the element in the loop

        Node* pointer = element_in_loop->next;
        int loopnos = 1;
        while(pointer!=element_in_loop){
            loopnos++;
            pointer = pointer->next;
        }
        cout << "\nThe number of elements in the loop are ... "<< loopnos<< "\n";
        //Found the number of elements in the loop

        Node* start = head;
        Node* kth;
        for(int i = 0;i<loopnos; i++){
            start = start->next;
        }

        // Found the kth element

        kth = start;
        start = head;

        while(kth->next != start->next){
            kth = kth->next;
            start = start->next;
        }
        kth->next = NULL;
        // loop removed
}
