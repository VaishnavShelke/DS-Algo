#include <bits/stdc++.h>
using namespace std;

/**
 * !            CONVERT A COMPLETE BINARY TREE TO A MIN HEAP          
 **/

struct Node
{
    int data;
    Node *left, *right;
};
 
struct Node* getNode(int data)
{
    struct Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


void heapify(vector<Node*>& heapTree,int size){
    int child = size-1;
    int parent = (child-1)/2;
    int temp;
    
    while(heapTree[parent]->data > heapTree[child]->data){
        temp = heapTree[child]->data;
        heapTree[child]->data = heapTree[parent]->data;
        heapTree[parent]->data = temp;     
        child = parent;
        parent = (child-1)/2; 
    }
}

void convertToMinHeapUtil(struct Node* root){

    vector<Node*> heapTree;
    int heapSize = 0;
 
    queue<Node*> qu; Node* parent;
    qu.push(root); int size;

    while(!qu.empty()){
        parent = qu.front();
        heapTree.push_back(parent);
        qu.pop();

        if(parent->left != NULL) qu.push(parent->left);
        if(parent->right != NULL) qu.push(parent->right);
    }


    for(size = 2; size<=heapTree.size(); size++){
        heapify(heapTree,size);
    }
    
}

void preorderTraversal(struct Node* root){

    if(root == NULL) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    struct Node *root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);

    convertToMinHeapUtil(root);
    cout << "Preorder Traversal:" << endl;
    preorderTraversal(root);
 
    return 0;
}
