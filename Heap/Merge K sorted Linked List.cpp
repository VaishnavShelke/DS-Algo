#include <bits/stdc++.h>
using namespace std;

// MERGE K SORTED LINKED LIST

class Node{
public:
    int data; Node* next;
    Node(){ next = NULL;}
    Node(int data) { this->data = data; next = NULL;}
};

Node* newNode(int data){
    Node* temp = new Node(data);
    return temp;
};

class comparer{
public:
    bool operator()(Node* n1,Node* n2){        // This is called operator overloading
        return n1->data > n2->data;             // We want greater number at the top
    }
};

Node* mergeKSortedLists(Node* arr[],int k){

    priority_queue<Node*,vector<Node*>,comparer> pq;

    Node* meargedList = new Node(INT_MAX);
    Node* current = meargedList;

    for(int i = 0; i<k ; i++){
        if(arr[i] != NULL) { pq.push(arr[i]); arr[i] = arr[i]->next;}
    }
    while(!pq.empty()){
        for(int i = 0; i<k ; i++){
            if(arr[i] != NULL){
                pq.push(arr[i]); arr[i] = arr[i]->next;
            }
        }
        meargedList->next = pq.top();
        meargedList = meargedList->next;
        pq.pop();

    }
    return current->next;
}

void printList(Node* head){
    Node* current;
    current = head;

    while(current != NULL){
        cout << current->data << " --> ";
        current = current->next;
    }
    return;
}


int main()
{
    int k = 3; // Number of linked lists
    int n = 4; // Number of elements in each list
    Node* arr[k];
 
    // creating k = 3 sorted lists
    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);
 
    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);
 
    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);
 
    // merge the k sorted lists
    Node* head = mergeKSortedLists(arr, k);
 

    // print the merged list
    printList(head);
 
    return 0;
}
