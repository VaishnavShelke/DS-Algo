#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/**
 * !                              Diagonal Print                     
 * ?                                                          
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




void diagonalPrint(leaf* root){
    
    queue<leaf*> qu;
    leaf* parent;
    qu.push(root);

    while(!qu.empty()){
        parent = qu.front();
        qu.pop();
        while(parent!= NULL){
            cout << " " << parent->data;
            if(parent->left != NULL) qu.push(parent->left);
            parent = parent->right;
        }
    }
    return;
}

int main()
{
    leaf* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);

    diagonalPrint(root);
    
    return 0;
}
