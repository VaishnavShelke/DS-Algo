#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/**
 * !  MIRROR A TREE      
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

void mirrorTree(leaf* root){

    if(root == NULL) return;
    leaf* temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
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
    leaf *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout <<" Before Mirroring .... \n";
    levelOrder(root);
    mirrorTree(root);
    cout << "\nAfter Mirroring .....\n";
    levelOrder(root);
    return 0;
}
