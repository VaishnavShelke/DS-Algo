#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//  Find LCA of given two numbers in a Binary Search Tree

class Node{
public:
    int data; Node *left, *right;
    Node* next;
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


Node* findLCA(Node* root,int n1,int n2){

    if(root == NULL) return NULL;

    if(root->data > n1 && root->data > n2){
        return findLCA(root->left,n1,n2);
    }
    else if(root->data < n1 && root->data < n2){
        return findLCA(root->right,n1,n2);
    }
    else{
        return root;
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
    
    Node* LCA = findLCA(root->returnHead(),100,350);
    if(LCA == NULL){
        cout << "Both Numbers non existent ... ";
    }
    else{
        cout << " The LCA is ... " << LCA->data;
    }
   return 0;
}
