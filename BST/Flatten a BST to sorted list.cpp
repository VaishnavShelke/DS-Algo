#include <bits/stdc++.h>
using namespace std;
 
// Flatten a BST to sorted list

struct node {
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void print(node* parent)
{
    node* curr = parent;
    while (curr != NULL)
        cout << curr->data << " ", curr = curr->right;
}
 
void inOrderTraversal(node* root,node*& prev){

    if(root == NULL) return;

    inOrderTraversal(root->left,prev);
    prev->right = root;
    root->left = prev;
    prev = root;
    inOrderTraversal(root->right,prev);
}

void flatten(node* root){

    node* dummy = new node(INT_MAX);
    node* prev = dummy;
    inOrderTraversal(root,prev);

    node* head = dummy->right;
    head->left = NULL;
    delete dummy;
    node* current = head;
    while(current != NULL){
        cout << current->data << " ";
        current = current->right;
    }
    return;    

}

 
// Driver code
int main()
{
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);
 
    // Calling required function
    flatten(root);
 
    return 0;
}
