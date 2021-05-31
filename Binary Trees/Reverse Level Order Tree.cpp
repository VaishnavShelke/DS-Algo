#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/**
 * !  LEVEL ORDER TRAVERSAL of a BINARY TREE  
 **/

class leaf{
public:
    int data;
    leaf* left; leaf* right;
    leaf(){left = NULL; right = NULL;}
};

leaf* newNode(int data){
    leaf* temp; temp = new leaf;
    temp->data = data;
    return temp;
}

void printLevelOrder(leaf* root){
    queue<leaf*> qu;
    qu.push(root);
    stack<int> stc;
    leaf* parent;
    
    while(!qu.empty()){
        parent = qu.front();
        stc.push(parent->data);
        qu.pop();

        if(parent->right != NULL){
            qu.push(parent->right);
        } 
        if(parent->left != NULL){
            qu.push(parent->left);
        }
    }
    while(!stc.empty()) { cout << " -->> " << stc.top();stc.pop();}
    return;
}


int main()
{
    // Let us create binary tree shown in above diagram
    leaf *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Reverse L--->>R Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}
