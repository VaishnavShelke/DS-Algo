#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

/*
In this what we do is we break the current linked list into several linked list of size == k.
    And the remaiming unes into another linked list
While breaking the linked list we also reverse the ---->> to <<---- connnections in the linkedlist
        This we do till the kth element is reached and then store the pointer to this kth element
        in set_of_linked_list[0]
        and so on.
After getting the list of all these broken chains with each element of set_of_linked_list as the head of new lists formed
respectively.
We concanate them......
*/


// In this linked list all new elements are adde to the front of the linked list
class Node{
public:
    int data;
    Node* next = NULL;

};

class MyList{
public:
    Node* head;

    MyList() {head = NULL;};
    void MyAppend(int data);
    void MyRemove();
    void printLR();

    void iterativereverse();
};

void MyList :: MyAppend(int data){
    Node* temp = new Node;
    temp->data = data;
    cout <<"New element added == "<< data << "\n";
    if(head == NULL){
        head = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}

// Remove elements from the beginning only
void MyList :: MyRemove(){
    if (head == NULL){
        cout << "\nList Already Empty\n";
        return;
    }
    else{
        cout << "Element removed == "<< head->data <<"\n";
        head = head->next;
    }
}

void MyList :: printLR(){
    Node* pointer;
    pointer = head;
    cout << "\nElements from L -->> R  ";
    while(pointer != NULL){
        cout << pointer->data << " ";
        pointer = pointer->next;
    }
    cout << "\n";
}



void MyList :: iterativereverse(){
    Node* current = head;
    Node* previous = NULL;
    Node* second;
    while(current != NULL){
        second = current->next;
        current->next = previous;
        previous = current;
        if (second == NULL) break;
        current = second;
    }
    head = current;
}


int main(){
        MyList linkedlist;
        int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
        int setof = 6;
        for(int i = 0; i<16 ; i++){
            linkedlist.MyAppend(arr[16-i-1]);
        }
        cout << "Original order ...\n";
        linkedlist.printLR();

        Node* current;
        Node* previous = NULL;
        Node* second;
        current = linkedlist.head;
        int counter = 0;
        Node* beginnings[16/setof+1];

        for(int i = 0; i<16/setof + 1;i++){
            previous = NULL;
            counter = 0;
            while(current!=NULL && counter < setof){
                second = current->next;
                current->next = previous;
                previous = current;
                current = second;
                counter++;
            }
            beginnings[i] = previous;
        }
        linkedlist.head = beginnings[0];
        current = linkedlist.head;
        for(int i = 1;i<16/setof+1;i++){

            while(current->next != NULL){
                current = current->next;
            }
            current->next = beginnings[i];
            current = beginnings[i];
        }
        while(current->next != NULL){
                current = current->next;
            }
        cout << "\nInterval Reversal of linked list\n";
        linkedlist.printLR();
}
