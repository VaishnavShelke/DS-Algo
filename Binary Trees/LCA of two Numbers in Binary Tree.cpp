#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/**
 * !                        Find LCA in Binary Tree                     
 * *                        COMMON PATH TECHNIQUE                                                                                
 **/

class Node{
public: 
    int data;
    Node *left, *right;
    Node(){left = NULL; right = NULL;};
    Node(int data){left = NULL; right = NULL;this->data = data;}
};

Node* newNode(int data){
    Node* temp = new Node;
    temp->data = data;
    return temp;
}

bool findPath(Node* root,int n,vector<Node*>* path);
int findLCA(Node* root, int n1,int n2){

    vector<Node*> path1;
    vector<Node*> path2;
    Node* LCA;

    if(findPath(root,n1,&path1)&&findPath(root,n2,&path2)){
        
        path1.push_back(root);path2.push_back(root);
        int i = path1.size()-1; int j = path2.size()-1;
        while(i>=0 && j >= 0 && path1[i] == path2[j]){
            LCA = path2[j];
            i--;j--;
        }
                
        return LCA->data;
    }
    else{
        return INT_MAX;
    }
    
}

bool findPath(Node* root,int n,vector<Node*>* path){
    if(root == NULL) return false;
    if(root->data == n) return true;
    
    if(findPath(root->left,n,path)){
        path->push_back(root->left);
        return true;
    }
    if(findPath(root->right,n,path)){
        path->push_back(root->right);
        return true;
    }
    return false;

}
int main()
{
    // Let us create the Binary Tree shown in above diagram.
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
    
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
    return 0;
}
