
#include <bits/stdc++.h>
using namespace std;

// Program for n’th node from the end of a Linked List 

struct Node {
    int data;
    struct Node* next;
};
 
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
void printNthFromLast(Node* head,int n){
    Node* frontRunner;
    Node* backWard;
    backWard = head;
    frontRunner = head;
    int i;

    for(i = 0;i<n ; i++){
        if( frontRunner == NULL ) break;
        frontRunner = frontRunner->next;
    }
    if(frontRunner == NULL){
        if(i == n) cout << backWard->data;
        else  cout << "Incorrect Demand"; 
        return;
    }
    while(frontRunner->next != NULL){
        frontRunner = frontRunner->next;
        backWard = backWard->next;
    }

    cout << backWard->next->data;
    return ;
}

int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    // create linked 35->15->4->20
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);
 
    printNthFromLast(head, 2);
    return 0;
}
