#include <iostream>
#include <bits\stdc++.h>

using namespace std;

/**
 * !           Find pairs with given sum in doubly linked list                                
 * *          doubly linked list of positive distinct elements    
 **/

struct Node
{
    int data;
    struct Node *next, *prev;
};

void pairSum(Node* head,int x){

    Node* left = head, *right;

    while (head->next != NULL) head = head->next;

    vector<pair<int,int>> answer;
    
    right = head;
    while(left != right && right->next != left){
        if(left->data + right->data == x){
            answer.push_back(make_pair(left->data,right->data));
            left = left->next;
            right = right->prev;
        }
        else if(left->data + right->data < x){
            left = left->next;
        }
        else{
            right = right->prev;
        }
    }

    if(answer.size() == 0){
        cout << "No Such Pair Exists";
        return;
    }
    for(auto a: answer){
        printf("( %d, %d) \n",a.first,a.second);
    }
    return;
    
}

void insert(struct Node **head, int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
 
// Driver program
int main()
{
    struct Node *head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x = 7;
 
    pairSum(head, x);
 
    return 0;
}
