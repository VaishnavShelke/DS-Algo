#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/**
 * !                                   LEFT VIEW                                    
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

void LeftView(leaf* parent,int ht,int* depth){
    if(parent == NULL) return;
    if(ht>=*(depth)) {cout << parent->data << " "; *(depth) += 1;}
    if(parent->left != NULL) LeftView(parent->left,ht+1,depth);
    if(parent->right != NULL) LeftView(parent->right,ht+1,depth);    
    return;
}

void levelOrder(leaf* root){
    queue<leaf*> qu;
    qu.push(root);
    leaf* parent;

    while(!qu.empty()){
        parent = qu.front();
        qu.pop();
        cout << " --->> " << parent->data;

        if(parent->left != NULL){
            qu.push(parent->left);
        }
        if(parent->right != NULL){
            qu.push(parent->right);
        }
    }
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
    int depth = 0;
    LeftView(root,0,&depth);
    return 0;
}
