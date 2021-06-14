#include <bits/stdc++.h>
using namespace std;



struct Node
{
    int data;
    struct Node *next;
};
 
void segregateEvenOdd(Node** head){

 
    /* Let us create a sample linked list as following
    0->1->4->6->9->10->11 */
    Node* odd = new Node();
    Node* even = new Node();
    Node* headEven = even;
    Node* headOdd = odd;
    Node* current  = *head;

    while(current != NULL){
        if(current->data % 2 == 0){
            even->next = current;
            even = even->next;
        }
        else{
            odd->next = current;
            odd = odd->next;
        }
        current = current->next;
    }
    if(even != NULL) even->next = NULL;
    if(odd != NULL) odd->next = NULL;

    headEven = headEven->next;
    headOdd = headOdd->next;

    current = headEven;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = headOdd;

    *head = headEven;


}

void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 

void printList(struct Node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;

 
    push(&head, 11);
    push(&head, 10);
    push(&head, 9);
    push(&head, 6);
    push(&head, 4);
    push(&head, 1);
    push(&head, 0);
 
    printf("\nOriginal Linked list \n");
    printList(head);
 
    segregateEvenOdd(&head);
 
    printf("\nModified Linked list \n");
    printList(head);
 
    return 0;
}
