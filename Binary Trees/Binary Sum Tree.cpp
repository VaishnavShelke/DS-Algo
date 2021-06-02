#include<iostream>
#include<bits\stdc++.h>

using namespace std;

// Sum of a Binary tree

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

int toSumTree(Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) {
        int nodeData = root->data;
        root->data = 0;
        return nodeData;}
    int data = root->data;   
    root->data = toSumTree(root->left) + toSumTree(root->right);
    return root->data + data;
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
    
    int trash = toSumTree(root);
    cout << "inOrder traversal of Binary sum tree ...\n";
    inOrder(root);
    return 0;
}
