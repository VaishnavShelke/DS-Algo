#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* next;
};
 
Node* reverseLL(Node* root,Node** head);
void delLesserNodes(Node** head){

    reverseLL(*head,head)->next = NULL;

    Node* current = *head;
    int baap = current->data;

    Node* back = NULL;
    Node* front = current->next;
    while(front != NULL){
        if(current->data < baap){
            if(back != NULL){
                back->next = front;
                current = front;
                front = front->next;
            }
            else{
                *head = front;
                back = NULL;
                current = front;
                front = front->next;
            }
        }
        else{
            baap = current->data;
            back = current;
            current = front;
            front = front->next;
        }
    }
    if(current->data<baap){
        back->next = NULL;
    }

    reverseLL(*head,head)->next = NULL;



}

Node* reverseLL(Node* root,Node** head){
    if (root->next == NULL) {
        *head = root;
        return root;
    }
    Node* current = root;
    reverseLL(current->next,head)->next = current;

    return current;
}
 

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
 


void printList(struct Node* head)
{
    while (head != NULL)
    {
        cout << " " << head->data ;
        head = head->next;
    }
    cout << "\n" ;
}
 
int main()
{
    struct Node* head = NULL;
 
    /* Create following linked list
    12->15->10->11->5->6->2->3 */
    push(&head, 3);
    push(&head, 2);
    push(&head, 6);
    push(&head, 5);
    push(&head, 11);
    push(&head, 10);
    push(&head, 15);
    push(&head, 12);
 
    cout << "Given Linked List \n" ;
    printList(head);
 
    delLesserNodes(&head);
 
    cout << "Modified Linked List \n" ;
    printList(head);
 
    return 0;
}
