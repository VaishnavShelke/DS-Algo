#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/**
 * !                            RIGHT VIEW                                  
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

void rightView(leaf* root,int ht,int* depth){

    
    if(ht > *depth) {cout << root->data << " ---> "; *(depth) += 1;}
    if(root->right != NULL) rightView(root->right,ht + 1,depth);
    if(root->left != NULL) rightView(root->left,ht+1,depth);

    return;
}

int main()
{
    // Let us create binary tree shown in above diagram
    leaf* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->left->left = newNode(5);
    root->left->left->left->left = newNode(9);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
    int depth = -1;
    rightView(root,0,&depth);
    return 0;
}
