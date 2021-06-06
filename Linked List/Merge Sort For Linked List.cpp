#include<iostream>
#include<bits\stdc++.h>

using namespace std;

/**
 * !                   MEARGE SORT LINKED LIST                 
 **/

class Node{
public: 
    int data;
    Node *next;
    Node(){next = NULL;};
    Node(int data){next = NULL;this->data = data;}
};

Node* newNode(int data){
    Node* temp = new Node;
    temp->data = data;
    return temp;
}

Node* splitLink(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
        fast = fast->next; slow = slow->next;
    }
    Node* temp = slow->next;
    slow->next = NULL;
    return temp;
}

Node* mearge(Node* first, Node* second){
    Node* result = new Node(INT_MAX);
    Node* resultantH = result;
    while(first != NULL || second != NULL){
        if(first == NULL){
            result->next = second; second = second->next;
        }
        else if(second == NULL){
            result->next = first; first = first->next;
        }
        else{
            if(first->data<second->data){
                result->next = first; first = first->next;
            }
            else{
                result->next = second; second = second->next;
            }
        }
        result = result->next;
    }
    resultantH = resultantH->next;
    return resultantH;
}


Node* meargeSort(Node* head){

    if(head == NULL) return NULL;
    if(head->next == NULL) return head;

    Node* first = head;
    Node* second = splitLink(head);

    first = meargeSort(first);
    second = meargeSort(second);

    Node* meargedLink = mearge(first,second);
    return meargedLink;
}




int main(){
    Node* head = newNode(4);
    head->next = newNode(3);
    head->next->next = newNode(5);
    head->next->next->next = newNode(7);
    head->next->next->next->next = newNode(6);
    head->next->next->next->next->next = newNode(9);
    head->next->next->next->next->next->next = newNode(10);

    head = meargeSort(head);

    Node* current = head;

    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
}






