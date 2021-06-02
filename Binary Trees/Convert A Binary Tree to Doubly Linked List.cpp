#include<iostream>
#include<bits\stdc++.h>

using namespace std;

// Convert A BiNARY TREE TO DOUBLY LINKED LIST OR LINKED LIST


class Node{
public:
    int data; Node *left, *right;
    Node(){left = NULL; right = NULL;}
    Node(int data){ this->data = data; left = NULL; right = NULL;}
};

Node* newNode(int data){
    Node* temp = new Node(data);
    return temp;
}

pair<Node*,Node*> convertToQueue(Node* root){
    
    if (root == NULL) {
        pair<Node*, Node*> startEnd;
        startEnd.first = NULL;
        startEnd.second = NULL;
        return startEnd;
    }
    pair<Node*, Node*> startEnd;
    
    pair<Node*,Node*> leftRow = convertToQueue(root->left);
    pair<Node*,Node*> rightRow = convertToQueue(root->right);
    
    if(leftRow.first != NULL){
        leftRow.second->right = root;
        root->left = leftRow.second;
        startEnd.first = leftRow.first;
    }
    else{
        startEnd.first = root;
    }

    if(rightRow.first != NULL){
        root->right = rightRow.first;
        rightRow.first->left = root;
        startEnd.second = rightRow.second;
    }
    else{
        startEnd.second = root;
    }

    return startEnd;   
}
void inOrder(Node* root){
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);

    return;
}


int main(){
    Node* root;
    root = newNode(10); 
    root->left = newNode(-2); 
    root->right = newNode(6); 
    root->left->left = newNode(8); 
    root->left->right = newNode(-4); 
    root->right->left = newNode(7); 
    root->right->right = newNode(5); 
   

    pair<Node*,Node*> par = convertToQueue(root);
    Node* start = par.first;
    while(start != NULL){
        cout << start->data << "   "; start = start->right;
    }
    return 0;
}
