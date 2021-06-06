#include <iostream>
#include <bits\stdc++.h>
using namespace std;


/**
 * !                    Sort a linked ists with only zeroes and ones and twos                              
 * *                                               
 **/

class Node
{
    public:
    int data;
    Node* next;
    Node(){ next = NULL;}
    Node(int data){ next = NULL; this->data = data;}
};

Node* newNode(int data){
    Node* temp = new Node(data);
    return temp;
}


void sortList(Node** head){

    Node* zeroHead; Node* oneHead;
    Node* current;Node* temp;

    Node* start;
    Node* node3 = new Node(2); node3->next = *head;
    oneHead = new Node; oneHead->data = 1; oneHead->next = node3;
    zeroHead = new Node; zeroHead->data = 0; zeroHead->next = oneHead;

    start = zeroHead;
    Node* parent;
    parent = node3;
    current = *head;
    while(current != NULL){
        if(current->data == 1){
            temp = current;
            parent->next = current->next;
            temp->next = oneHead->next;
            oneHead->next = temp;
            oneHead = oneHead->next;
            current = parent->next;
        }
        else if(current->data == 0){
            temp = current;
            parent->next = current->next;
            temp->next = zeroHead->next;
            zeroHead->next = temp;
            zeroHead = zeroHead->next;
            current = parent->next;
        }
        else{
            parent = current;
            current = current->next;
        }
    }

    set<int> num012;
    num012.insert(0);

    start = start->next;

    current = start;
    while(current->next != NULL){
        if(num012.find(current->next->data) == num012.end()){
            num012.insert(current->next->data);
            current->next = current->next->next;
        }
        current = current->next;
    }
    *head = start;

}
int main(void)
{
    Node *head = newNode(1);

    head->next = newNode(1);
    head->next->next = newNode(1);
    head->next->next->next = newNode(1);
    head->next->next->next->next = newNode(1);
    head->next->next->next->next->next = newNode(1);
    head->next->next->next->next->next->next = newNode(1);
    head->next->next->next->next->next->next->next = newNode(2);
    head->next->next->next->next->next->next->next->next = newNode(2);


 
    sortList(&head);
 
    Node* current = head;

    cout << "The sorted list is .... ";
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
   
 
    return 0;
}
