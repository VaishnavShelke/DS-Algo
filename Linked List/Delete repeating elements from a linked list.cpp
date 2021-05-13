#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;

// Delete repeating elements in a linked list
class Node{
public:
    int value;
    Node* next;
    Node* newnode(int data);
};

class Node :: Node* newNode(int data){
    Node* temp = new Node;
    temp->value = data;
    temp->next = NULL;
    return temp;
};

int main(){
    /* The constructed linked list is:
     10->12->11->11->12->11->10*/
    struct Node *start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(11);
    start->next->next->next = newNode(11);
    start->next->next->next->next = newNode(12);
    start->next->next->next->next->next =
                                    newNode(11);
    start->next->next->next->next->next->next =
                                    newNode(10);

    unordered_set<int> seen;

    Node* current = start;
    Node* previous = NULL;
    // Printing the Linked list:
    cout << "Linked list initially ....  \n";
    current = start;
    while(current != NULL){
        cout << current->value << " -->> ";
        current = current->next;
    }

    current = start;
    while(current != NULL){
        if(seen.find(current->value) != seen.end()){
            previous->next = current->next;
            previous = previous;
            delete current;
        }
        else{
            seen.insert(current->value);
            previous = current;
        }
        current = previous->next;
    }

    // Printing the Linked list:
    cout << "\n\nLinked List Afterwards .... \n";
    current = start;
    while(current != NULL){
        cout << current->value << " -->> ";
        current = current->next;
    }

    return 0;

}
