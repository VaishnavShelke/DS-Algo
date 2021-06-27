#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int key;
    Node *left, *right;
};
 
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
  
Node* insert(Node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
 
void kthLargest(Node* root,int k,int& index){

    if(index>=k) return;
    if(root == NULL) return;
    kthLargest(root->left,k,index);
    index++;
    if(index == k){
        cout << root->key << " ";
    }
    kthLargest(root->right,k,index);

    return;
}

int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    int c = 0;
    int index;
    for (int k=1; k<=7; k++)
        {  index = 0;
        kthLargest(root, k,index);}
 
    return 0;
}
