#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/**
 * !                       Largest Independent Set                        
 * *                                                                                                  
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

int LSWI(Node* root,int incl,map<Node*,int[2]>* memo){
    cout << "Hello ...  ";
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL){
        if(incl == 1) return 1;
        else return 0; 
    }
    
    if((*(memo))[root][incl] != INT_MIN){
        return (*(memo))[root][incl];
    }
    
    int l1 = LSWI(root->left,1,memo);
    int l0 = LSWI(root->left,0,memo);
    int r1 = LSWI(root->right,1,memo);
    int r0 = LSWI(root->right,0,memo);
    int independent;
    if(incl == 0){
        independent = l1 + r1;
        independent = max(independent,l1 + r0);
        independent = max(independent,l0 + r1);
        independent = max(independent,l0 + r0);
    }
    else{
        independent = l0 + r0;
    }

    (*(memo))[root][incl] = independent;
    return independent;
}
int LISS(Node* root){
    queue<Node*> qu;
    qu.push(root);
    Node* parent;
    map<Node*,int[2]> memo;

    while(!qu.empty()){
        parent = qu.front();
        qu.pop();
        memo[parent][0] = INT_MIN;
        memo[parent][1] = INT_MIN;
        if(parent->left != NULL){
            qu.push(parent->left);
        }
        if(parent->right != NULL){
            qu.push(parent->right);
        }

    }
    return max(LSWI(root,0,&memo),1+LSWI(root,1,&memo));
}

int main()
{
    // Let us construct the tree given in the above diagram
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
 
    printf ("Size of the Largest Independent Set is %d ", LISS(root));
 
    return 0;
}
