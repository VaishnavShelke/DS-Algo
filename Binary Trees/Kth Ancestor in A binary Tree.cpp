#include <bits/stdc++.h>
using namespace std;
  
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
  
void myKthAncestor(Node* root,int key,int kth,int depth,Node** ourNode){
    static int stcDepth = -1;
    if(stcDepth != -1) return;
    if(root == NULL) return;

    if(root->data == key){
        stcDepth = depth - kth;
        return;
    }

    myKthAncestor(root->right,key,kth,depth+1,ourNode);
    
    myKthAncestor(root->left,key,kth,depth+1,ourNode);
   
    if(stcDepth == depth){
        *ourNode = root;
    }
    return;
}

int kthAncestor(Node* root,int key,int kth){
    Node* ourNode = NULL;

    myKthAncestor(root,key,kth,0,&ourNode);
    if(ourNode == NULL) return INT_MAX;
    return ourNode->data;
}

int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(3);
    root->left = newNode(1);
    root->right = newNode(4);
    root->left->left = newNode(0);
    root->left->right = newNode(2);
  
    int k = 3;
    int node = 2;
 
    // print kth ancestor of given node
    cout<<kthAncestor(root,node,k);
    return 0;
}
