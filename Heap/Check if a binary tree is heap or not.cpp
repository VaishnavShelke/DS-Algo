#include <bits/stdc++.h>
using namespace std;

// Check if a binary tree is heap or not

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int k)
{
    struct Node *node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}

void traverseTree(struct Node* root,int pos,int* size,int* maxPos,bool* flag){

    if(root == NULL) return;
    if(root != NULL) *size += 1;

    *maxPos = max(*maxPos,pos);

    if(root->left != NULL && root->right != NULL){
        if(root->left->key <= root->key && root->right->key <= root->key){}
        else *flag = true;
    }
    else{
        if(root->left != NULL){
            if(root->left->key>root->key) *flag = true;
        }
    }

    traverseTree(root->left,2*pos+1,size,maxPos,flag);
    traverseTree(root->right,2*pos+2,size,maxPos,flag);
    return;
}

bool isHeap(struct Node* root){

    int size = 0; bool flag = false;
    int maxPos = 0;
    traverseTree(root,0,&size,&maxPos,&flag);
    cout << size << " " << maxPos << " " << flag << endl;
    if(flag) return false;
    if(size<= maxPos) return false;
    return true;
}

int main()
{
    struct Node* root = NULL;
    root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(2);
    root->left->right->left = newNode(1);
  
    // Function call
    if (isHeap(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";
  
    return 0;
}
