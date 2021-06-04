#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/**
 * !                       Find Distance Between two Nodes In a Tree                        
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
int findDistance(Node* root, int n1,int n2){

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
                
        return i+j+2;
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
    // Let us create binary tree given in the
    // above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
    return 0;
}
