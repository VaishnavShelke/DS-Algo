#include <bits/stdc++.h>
using namespace std;

// Construct Binary Tree from inorder and preorder Traversal

class Node{
public:
    char data; Node* left; Node* right;
    Node(){left = NULL; right = NULL;}
    Node(int data){ this->data = data; left = NULL; right = NULL;}
};


Node* buildTree(char* inorder,char* preorder,int low,int high){
    static int preIndex = 0;
    if(low>high) return NULL;
    Node* parent = new Node(preorder[preIndex]);
    int middle;
    for(int i = low; i<= high; i++){
        if(inorder[i] == preorder[preIndex]){
            middle = i; break;
        }
    }

    preIndex = preIndex + 1;

    parent->left = buildTree(inorder,preorder,low,middle-1);
    parent->right = buildTree(inorder,preorder,middle+1, high);

    return parent;
}

void printInorder(Node* root){
    if(root == NULL) return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main()
{
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
    Node* root = buildTree(in, pre, 0, len - 1);
 
    /* Let us test the built tree by
    printing Insorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
}
