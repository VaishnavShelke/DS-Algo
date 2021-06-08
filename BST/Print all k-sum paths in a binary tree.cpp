#include <iostream>
#include <bits\stdc++.h>
#define N 9
using namespace std;


// Print all k-sum paths in a binary tree


struct Node
{
    int data;
    Node *left,*right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void printPath(vector<int> &path,int base,int incend){
    for(int i = base; i<= incend; i++){
        cout << path[i] << " ";
    }
    cout << endl;
}

void printKPath(Node* root,int sum,vector<int>& path){

    if(root == NULL) return;

    path.push_back(root->data);

    int k = 0;
    for(int j = path.size()-1; j>=0 ; j--){
        k += path[j];
        if(k == sum){
            printPath(path,j,path.size()-1);
        }
    }


    if(root->left != NULL)
        printKPath(root->left,sum,path);
    if(root->right != NULL)
        printKPath(root->right,sum,path);
    
    path.pop_back();
    return;
}


int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);
  
    int k = 5;
    vector<int>path;
    printKPath(root, k,path);
  
    return 0;
}

