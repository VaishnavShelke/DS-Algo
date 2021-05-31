#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/**
 * !  DIAMETER OF A TREE      
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

int maxHeight(leaf* root,int* maxima){
    
    if(root == NULL) return 0;

    int rightHt = maxHeight(root->right,maxima);
    int leftHt = maxHeight(root->left,maxima);
    *maxima = max(*maxima,rightHt + leftHt + 1);
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
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    int maxima = INT_MIN;
    int ht = maxHeight(root,&maxima);
    cout << "Diameter of tree ..... " << maxima;
    return 0;
}
