#include <bits/stdc++.h>
using namespace std;


// Print Kth smallest number;

// A BST node
struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
 
Node* insert(Node* root, int x)
{
    if (root == NULL)
        return new Node(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}
 
void printKthSmallest(Node* root,int kth){

    if(root == NULL) return;
    static int k = 0;
    static bool flag = false;
    if(flag) return;

    printKthSmallest(root->left,kth);
    k++;
    if(k == kth){ flag = true; cout << root->data;}
    printKthSmallest(root->right,kth);


    return;
}
 

int main()
{
    Node* root = NULL;
    int keys[] = { 20, 8, 22, 4, 12, 10, 14 };
 
    for (int x : keys)
        root = insert(root, x);
 
    int k = 2;
    printKthSmallest(root, k);
    return 0;
}
