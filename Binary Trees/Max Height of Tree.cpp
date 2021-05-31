#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/**
 * !  MAX HEIGHT OF A TREE  
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

int maxHeight(leaf* root){
    
    if(root == NULL) return 0;

    int rightHt = maxHeight(root->right);
    int leftHt = maxHeight(root->left);

    return (max(rightHt,leftHt) + 1);
}

int main()
{
    // Let us create binary tree shown in above diagram
    leaf *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Max Height ..... " << maxHeight(root);
    return 0;
}
