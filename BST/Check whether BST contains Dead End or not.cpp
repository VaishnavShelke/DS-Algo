#include<bits/stdc++.h>
using namespace std;

// Check whether BST contains Dead End or not 

struct Node
{
    int data;
    struct Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
struct Node* insert(struct Node* node, int key)
{
    if (node == NULL) return newNode(key);
 
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
 
    return node;
}
 
bool isLeaf(Node* root){
    if(root->right == NULL && root->left == NULL){
        return true;
    }
    else{
        return false;
    }
} 

void ultaInorder(Node* root,int sucessor,bool& flag){

    if(root == NULL || flag){
        return;
    }
    ultaInorder(root->right,sucessor,flag);
    if(isLeaf(root)){
        if(root->data + 1 == sucessor){
            flag = true;
        }
    }
    sucessor = root->data;
    ultaInorder(root->left,sucessor,flag);
    return;
}

void sidhaInorder(Node* root,int predecessor,bool& flag){

    if(root == NULL || flag){
        return;
    }
    sidhaInorder(root->left,predecessor,flag);
    if(isLeaf(root)){
        if(root->data - 1 == predecessor){
            flag = true;
        }
    }
    predecessor = root->data;
    sidhaInorder(root->right,predecessor,flag);
    return;
}

bool isDeadEnd(Node* root){
    bool flag = false;
    int sucessor = INT_MAX;
    int predecessor = 0;
    ultaInorder(root,sucessor,flag);
    if(!flag) sidhaInorder(root,predecessor,flag);
    return(flag);
}

 
// Driver program
int main()
{
/*       8
       /   \
      5    11
     /  \
    2    7
     \
      3
       \
        4 */
    Node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    //root = insert(root, 7);
    root = insert(root, 11);
    //root = insert(root, 4);
    if (isDeadEnd(root) == true)
        cout << "Yes " << endl;
    else
        cout << "No " << endl;
    return 0;
}
