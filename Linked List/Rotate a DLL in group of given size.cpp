#include<iostream>
#include <bits/stdc++.h>

using namespace std;

// Rotate a DLL in group of given size
  

struct Node {
    int data;
    Node *next, *prev;
};
  
Node* getNode(int data)
{
    // allocate space
    Node* new_node = (Node*)malloc(sizeof(Node));
  
    // put in the data
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}
  
void push(Node** head_ref, Node* new_node)
{
    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}
 
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
  
Node* reverseMe(Node* head){

    Node* back = NULL;
    Node* current = head;
    Node* front = current->next;

    while(current!=NULL){
        current->next = back;
        current->prev = front;
        back = current;
        current = front;
        if(front != NULL)front = front->next;
    }

    return back;
}

Node* revListInGroupOfGivenSize(Node* head,int k){

    vector<Node*> heads;
    Node* current = head;
    Node* start;
    Node* temp;

    while(current != NULL){

        start = current;
        for(int i = 0; i<k-1 && current != NULL ; i++){
            current = current->next;
        }
        if(current != NULL) temp = current->next;
        if(current != NULL) current->next = NULL;

        heads.push_back(reverseMe(start));
        if(current != NULL)current = temp;
    }
    start = heads[0];

    for(int i = 1; i<heads.size(); i++){
        
        while(start->next != NULL){
            start = start->next;
        }
        start->next = heads[i];
    }
    return heads[0];

}



int main()
{
    // Start with the empty list
    Node* head = NULL;
  
    // Create doubly linked: 10<->8<->4<->2
    push(&head, getNode(2));
    push(&head, getNode(4));
    push(&head, getNode(8));
    push(&head, getNode(10));
    push(&head, getNode(2));
    push(&head, getNode(4));
    push(&head, getNode(8));
    push(&head, getNode(10));
     
    int k = 20;
  
    cout << "Original list: ";
    printList(head);
  
  
    head = revListInGroupOfGivenSize(head, k);
  
    cout << "\nModified list: ";
    printList(head);
  
    return 0;
}
