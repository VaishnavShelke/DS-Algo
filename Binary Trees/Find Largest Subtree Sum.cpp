
#include <bits/stdc++.h>
using namespace std;


// Find Maximum Sum Subtree

struct Node {
    int key;
    Node *left, *right;
};

Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

int findLargestSS(Node* root,Node** maxi,int* superMax){

    if(root == NULL) return 0; 
    int sumTree = findLargestSS(root->left,maxi,superMax) + findLargestSS(root->right,maxi,superMax) + root->key;
    
    if(sumTree > *superMax){
        *superMax = sumTree;
        (*maxi) = root;
    }

    return sumTree;
}

Node* findLargestSubtreeSum(Node* root){
    Node* maxi;
    int superMax = INT_MIN;
    int trash = findLargestSS(root,&maxi,&superMax);

    return maxi;
} 
  

int main()
{
    /*
               1
             /   \
            /     \
          -2       3
          / \     /  \
         /   \   /    \
        4     5 -6     2
    */
  
    Node* root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);
  
    Node* maxTree = findLargestSubtreeSum(root);
    cout << maxTree->key;
    return 0;
}
