#include <bits/stdc++.h>
#include<iostream>
using namespace std;

// Check wether a tree is BST or Not

class Node{
public:
    int data; Node *left, *right;
    Node(){left = NULL; right = NULL;}
    Node(int data){left = NULL; right = NULL; this->data = data;}
};

class BST{
private:
    Node* head;
public:
    BST(){head = NULL;}
    BST(int data){ head = new Node(data);}
    Node* returnHead(){
        return head;
    }
    Node* insertBST(Node* parent,int child){
    
        if(parent == NULL){
            parent = new Node;
            parent->data = child;
            return parent;
        }
        if(parent->data<child){
            parent->right = insertBST(parent->right,child);
        }
        else{
            parent->left = insertBST(parent->left,child);
        }
        return parent;
    }
    void insert(int value){
        head = insertBST(this->head,value);
    }
     
    void inorderBST(Node* root){
        if(root == NULL) return;
        inorderBST(root->left);
        cout << root->data << " ";
        inorderBST(root->right);
        return;
    }
    void inorder(){
        inorderBST(this->head);
    }
};

void inOrder(Node* root,int* prev){

    if(root == NULL) return;

    inOrder(root->left,prev);

    if(root->data>*prev) *prev = root->data;
    else *prev = INT_MAX;

    inOrder(root->right,prev);

    return;
}
bool checkBST(Node* root){
    int prev = INT_MIN;
    inOrder(root,&prev);
    if(prev == INT_MAX){
        return false;
    }
    else{
        return true;
    }
}
int main()
{
    /* Let us create following BST
            50
        /     \
        30     70
        / \ / \
    20 40 60 80 */

    
    BST* root = new BST;
    root->insert(50);
    root->insert(30);
    root->insert(20);
    root->insert(40);
    root->insert(70);
    root->insert(60);
    root->insert(80);
    root->insert(10);
    root->insert(35);
    //root->returnHead()->right->left->left = new Node(45);
    root->inorder();
    cout << "\nWether BST or not ... " << checkBST(root->returnHead());
    return 0;
   
}
