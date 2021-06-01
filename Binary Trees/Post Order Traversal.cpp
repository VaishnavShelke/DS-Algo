#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/**
 * !                              Post Order Traversal                                  
 **/

class leaf{
public: 
    int data;
    leaf *left, *right;
    leaf(){left = NULL; right = NULL;};
    leaf(int data){left = NULL; right = NULL;this->data = data;}
};

leaf* newNode(int data){
    leaf* temp = new leaf;
    temp->data = data;
    return temp;
}

void postOrder(leaf* root){
    //HEAD LEFT RIGHT
    stack<leaf*> stc;
    stc.push(root);
    leaf* parent;

    while(!stc.empty()){
        parent = stc.top();
        stc.pop();
        cout << parent->data << " ---> ";
        if(parent->right != NULL) stc.push(parent->right);
        if(parent->left != NULL) stc.push(parent->left);
    }
    return;
}



int main()
{
    // Let us create binary tree shown in above diagram
    leaf* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
    postOrder(root);
    return 0;
}
