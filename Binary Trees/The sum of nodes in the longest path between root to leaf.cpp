#include <iostream>
#include <bits\stdc++.h>
#define N 9
using namespace std;

// The sum of nodes in the longest path between root to leaf

struct Node {
    int data;
    Node* left, *right;
};
 

Node* getNode(int data)
{

    Node* newNode = (Node*)malloc(sizeof(Node));
 

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void SumOfLongRootToLeafPathUtil(Node* root,int depth,int* deepest,int sum,int* deepestsum){

    
    if(root == NULL){
        if(depth>*deepest){
            *deepest = depth;
            *deepestsum = sum;
        }
        if(depth == *deepest){
            *deepestsum = max(*deepestsum,sum);
        }
        return;
    }
    sum = sum+root->data;
    
    SumOfLongRootToLeafPathUtil(root->left,depth+1,deepest,sum,deepestsum);
    SumOfLongRootToLeafPathUtil(root->right,depth+1,deepest,sum,deepestsum);

    return;
}

int sumOfLongRootToLeafPathUtil(Node* root){

    int deepest = INT_MIN;
    int sum = 0;
    int deepestsum = INT_MIN;
    SumOfLongRootToLeafPathUtil(root,0,&deepest,sum,&deepestsum);

    return deepestsum;
}
int main()
{
    // binary tree formation
    Node* root = getNode(4);         /*        4        */
    root->left = getNode(2);         /*       / \       */
    root->right = getNode(5);        /*      2   5      */
    root->left->left = getNode(7);   /*     / \ / \     */
    root->left->right = getNode(1);  /*    7  1 2  3    */
    root->right->left = getNode(2);  /*      /          */
    root->right->right = getNode(3); /*     6           */
    root->left->right->left = getNode(6);
 
    cout << "Sum = "
         << sumOfLongRootToLeafPathUtil(root);
 
    return 0;
}
