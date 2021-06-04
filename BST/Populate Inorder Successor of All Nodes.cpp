#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//  Populate Inorder Sucessor of Alll Nodes

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


void inOrder(Node* root,Node** prev){

    if(root == NULL) return;

    inOrder(root->left,prev);

    if(*prev == NULL){
        *prev = root;
    }
    else{
        
        (*(prev))->next = root;
        *prev = root;
    }
    

    inOrder(root->right,prev);

    return;
}
void popuateInorder(Node* root){
    Node* prev;
    inOrder(root,&prev);
    prev->next = NULL;
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
    cout << "Inorder By Inorder Function ...\n";
    root->inorder();
    popuateInorder(root->returnHead());

    Node* node = root->returnHead();

    while(node->left != NULL){
        node = node->left;
    }
    cout << "\n\nInorder by using next as additional Node Instance Member Variable ... \n";
    while(node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
    return 0;
   
}
