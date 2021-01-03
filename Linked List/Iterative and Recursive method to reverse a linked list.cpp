#include<iostream>
using namespace std;

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
    void recursivereverse() { Node* last = recursive(head); last->next = NULL; }
    Node* recursive(Node* start);
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

Node* MyList :: recursive(Node* current){
    Node* future;
    if(current->next == NULL){
        head = current;
        return current;
    }
    future = recursive(current->next);
    future->next = current;
    return current; 
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
    int arr[] = {1,2,3,4,5,6,7,8,9};
    MyList MYL;
    for (int i = 0; i<9 ; i++){
        MYL.MyAppend(arr[i]);
    }
    MYL.printLR();
    MYL.iterativereverse();
    cout << "\nReversed List\n";
    MYL.printLR();

}
