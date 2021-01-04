#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
    Approach is to store pointers to all visisted nodes in an unordered
    Map and verify the current node on which the pointer is present is in
    the set or not
*/
class Node{
public:
    int data;
    Node* next = NULL;
    Node(int dat) {
        data = dat;
    }
};

int main(){
    Node* head;
    
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(1e6);

    // Making a loop -->>>

     //head->next->next->next->next->next->next->next = head->next->next;

     // Loop made --->>>

    unordered_set<Node*> unset;
    Node* pointer = head;
    while(pointer!=NULL){
        if(unset.find(pointer) != unset.end()){
            cout << "Loop Detected";
            return 0;
        }
        else{
            unset.insert(pointer);
        }
        pointer = pointer->next;
    }
    cout << "No Loop Present";
    return 0;
}
