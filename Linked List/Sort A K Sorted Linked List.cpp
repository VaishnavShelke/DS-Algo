#include <bits/stdc++.h>
using namespace std;

// Sort A K Sorted Linked List


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
 

void pickandFront(Node* minimest,Node** start){
    // 3<->6<->2<->56<->8
    if(*start == minimest) return;
    Node* back = minimest->prev;
    Node* front = minimest->next;

    if(back != NULL){
        back->next = front;
        if(front != NULL) front->prev = back;

        // Minimest Removed

        minimest->next = *start;
        minimest->prev = (*start)->prev;
        if((*start)->prev != NULL) (*start)->prev->next = minimest;
        (*start)->prev = minimest;
        *start = minimest;
        // Minimest Added
    }
}

class comparer{
public:
    bool operator()(Node* n1, Node* n2){
        return n1->data > n2->data;
    }
};

void kSorted(Node** head,int k){
    
    
    Node* current = (*head); Node* start = (*head);
    Node* end, *minimest;
    priority_queue<Node*,vector<Node*>,comparer> pq;

    for(int i = 0; i<= k ; i++){
        pq.push(current);
        current = current->next;
    }
    end = current;

    minimest = pq.top();
    pq.pop();
    pickandFront(minimest,&start);
    *head = start;

    while(end != NULL){
        pq.push(end);
        end = end->next;
        start = start->next;
        minimest = pq.top();
        pq.pop();

        pickandFront(minimest, &start);
        
    }

    cout << endl << endl;
    while(!pq.empty()){
        start = start->next;
        minimest = pq.top();
        pq.pop();
        pickandFront(minimest,&start);
    }

}

 

 


void push(struct Node** head_ref, int new_data)
{
    
    struct Node* new_node =
        (struct Node*)malloc(sizeof(struct Node));
 
    
    new_node->data = new_data;
 
    new_node->prev = NULL;
 

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}
 
void printList(struct Node* head)
{
    // if list is empty
    if (head == NULL)
        cout << "Doubly Linked list empty";
 
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
 
int main()
{
    struct Node* head = NULL;
 
    // Create the doubly linked list:
    // 3<->6<->2<->12<->56<->8
    push(&head, 8);
    push(&head, 56);
    push(&head, 12);
    push(&head, 2);
    push(&head, 6);
    push(&head, 3);
 
    int k = 2;
 
    cout << "Original Doubly linked list:\n";
    printList(head);
    
    kSorted(&head,k);
 
    cout << "\nDoubly linked list after sorting:\n";
    printList(head);
 
    return 0;
}
