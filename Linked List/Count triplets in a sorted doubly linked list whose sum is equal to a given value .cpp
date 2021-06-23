#include <bits/stdc++.h>
using namespace std;
 
// structure of node of doubly linked list
struct Node {
    int data;
    struct Node* next, *prev;
};
 
int countTriplets(Node* head,int x){

    Node* current = head;
    int count = 0;
    while(current->next != NULL){
        current = current->next;
    }
    Node* tail = current;
    Node* first,*second,*third;

    first = head;
    while(first->next->next != NULL){
        second = first->next;
        third = tail;
        while(third != second){
            if(first->data + second->data + third->data == x) {
                count++; second = first->next; third = third->prev;
            }
            else if(first->data + second->data + third->data > x){
                third = third->prev;
            }
            else{
                second = second->next;
            }
        }
        first = first->next;
    }
    return count;
}


void insert(struct Node** head, int data)
{
    struct Node* temp = new Node();

    temp->data = data;
    temp->next = temp->prev = NULL;
 
    if ((*head) == NULL)
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
 
// Driver program to test above
int main()
{
    // start with an empty doubly linked list
    struct Node* head = NULL;
 
    // insert values in sorted order
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
 
    int x = 17;
 
    cout << "Count = "
         << countTriplets(head, x);
    return 0;
}
